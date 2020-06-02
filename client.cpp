#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "client.h"
#include <netinet/in.h>
#include <iostream>
#include <json.h>
#include <hashlib++/hashlibpp.h>



#include <string>
using namespace std;

Client::Client()
{
    sock=0;
}

string Client::newVSptr(string data, string type){
    Json::Value root;
    Json::StreamWriterBuilder wbuilder;
    wbuilder["data"] = data;
    wbuilder["type"] = type;

    string json = Json::writeString(wbuilder, root);
    this->sendStrMessage("new-vs;"+json+";");
    string id = this->askAnswer();
    return id;
}

void Client::delRef(string id){
    this->sendStrMessage("delete-ref;"+id+";");
}

void Client::addRef(string id){
    this->sendStrMessage("new-ref;"+id+";");
}

void Client::update(string id, string value){
    this->sendStrMessage("update;"+id+";"+value+";");
}

void Client::getType(string id, string value){
    this->sendStrMessage("get-type;"+id+";");
}

Json::Value toJson(string message){
    Json::Value val;
    Json::Reader reader;
    bool b = reader.parse(message, val);
    if (!b)
        cout << "Error: " << reader.getFormattedErrorMessages();
    return val;
}

void Client::saveCredentials(string credentials){
    Json::Value value=toJson(credentials);

    std::ofstream file;
    file.open("credentials.json");
    Json::StyledWriter styledWriter;
    file << styledWriter.write(value);

    file.close();
}

void Client::sendStrMessage(string messageSt){
    char mess[messageSt.size()+1];
    strcpy(mess, messageSt.c_str());
    send(sock , mess , strlen(mess), 1024 );
}


string Client::askAnswer(){
    char buffer[1024] = {0};
    read( sock , buffer, 1024);
    return (string) buffer;
}

string getmd5(string pass){
    md5wrapper md5=md5wrapper();
    pass=md5.getHashFromString(pass);
    return pass;
}

void Client::setServer(string ip, string port, string user, string password){
    this->ip=ip;
    this->port=port;
    this->user=user;
    this->password=password;
}

int Client::logIn()
{
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;

    try{
        serv_addr.sin_port = htons(std::stoi(port));
    }catch(std::invalid_argument& e){
        return -1;
    }

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    string password = getmd5(this->password);
    sendStrMessage("log-in;"+password+";"+user+";");
    string answer = this->askAnswer();

    if(answer=="connection failed"){
        return -1;
    }else{
        this->saveCredentials(answer);
        return 0;
    }
}

//
//  main.cpp
//  SearchEngineClient
//
//  Created by Xu ZHANG on 3/22/15.
//  Copyright (c) 2015 Xu ZHANG. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tcpconnector.h"

using namespace std;

int main(int argc, char** argv)
{
    int len;
    string message;
    char line[256];
    
    char ip[] = "localhost"; // IP地址。
    int port = 9999; // 端口号。
    
    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect(ip, port);
    if (stream) {
        message = "UPDATE(or QUERY) + DATA"; // 可以在这里用打头字母指示即将要让服务器进行的操作，后面接着被操作的DATA。
        stream->send(message.c_str(), message.size());
        printf("sent - %s\n", message.c_str());
        len = stream->receive(line, sizeof(line)); // 可以在这里接受服务器返回的信息，例如错误信息等。
        line[len] = NULL;
        printf("received - %s\n", line);
        delete stream;
    }
    
    exit(0);
}
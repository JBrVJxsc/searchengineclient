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
    char result[256]; // 视情况，可调整该缓存大小。
    //
    
    char ip[] = "localhost"; // IP地址。
    int port = 9999; // 端口号。
    
    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect(ip, port);
    if (stream) {
        string message = "UPDATE(or QUERY) + DATA"; // 在此处用打头字母指示即将要让服务器进行的操作，既“更新”或“查询”；后面接着被操作的DATA。
        stream->send(message.c_str(), message.size()); // 发送数据给服务器。
        int len = stream->receive(result, sizeof(result)); // 在此处接受服务器返回的信息，例如错误信息（更新）或结果（查询）等。
        result[len] = NULL;
        // 在此处处理result，例如显示错误信息或者显示结果等。
        // Do something here.
        printf("RESULT: %s\n", result);
        delete stream;
    }
    
    exit(0);
}
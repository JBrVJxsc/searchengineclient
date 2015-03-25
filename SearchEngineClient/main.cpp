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
    char result[512]; // buffer
    
    char ip[] = "localhost"; // IP address
    int port = 9999; // port
    
    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect(ip, port);
    
    bool isQuery = true;
    
    if (stream) {
        if (isQuery)
        {//send a query
            string message = "QUERY";
            string filequery = "dataset.hdf5";//the filename of query.
            message = message +" "+filequery;
            
            
            stream->send(message.c_str(), message.size()); // send data to server
            int len = stream->receive(result, sizeof(result)); // receive the message from server. err_msg or results
            
            result[len] = NULL;
            printf("Received:  %s\n", result);
            delete stream;
        }
        else
        {//send a update message
            string message = "UPDATE";
            string filequery = "dataset.hdf5";//the filename of query.
            message = message +" "+filequery;
            
            stream->send(message.c_str(), message.size()); // send data to server
            int len = stream->receive(result, sizeof(result)); // receive the message from server. err_msg or results
            
            result[len] = NULL;
            printf("Received:  %s\n", result);
            
            delete stream;
            
        }
        
    }
    
    exit(0);
}
// Copyright Arnt Gulbrandsen <arnt@gulbrandsen.priv.no>; BSD-licensed.

#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <string>

using namespace std;


class HttpServer
{
public:
    enum Operation { Get, Post, Invalid };

    HttpServer( int );
    ~HttpServer() {}

    void operator()() { start(); }

    void start();

    string readRequest();
    void parseRequest( string );
    void readBody();

    string body() const;
    int contentLength() const { return cl; }
    Operation operation() const { return o; }
    string path() const { return p; }

    void respond();
    void send( string );

    string httpResponse( int, const string &, const string & );

    void close();

private:
    string p;
    string b;
    Operation o;
    int cl;
    int f;
};


#endif

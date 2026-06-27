// Windows version
#define NICCENTMAINHASH "..."
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Coly.hpp"
using namespace std;
int main(int argc, char* argv[]){
    cout<<"Testing Server..."<<endl;
    string host = "127.0.0.1";
    string port = "12345";
    NetworkSession session;
    if (!connect_to_server(session, host, port)) {
        cout<<"ColyServer isn't running, starting ColyServer..."<<endl;
        RunCommand("C:\\Coly\\VariableSyncService\\ColyServer.exe");
        Sleep(1000);
    }
    if (!connect_to_server(session, host, port)) {
        cout<<"Failed to connect to server" << endl;
        cout<<"Please check did you have install Coly."<<endl;
        return 1;
    }
    cout<<"Checking if the Coly Framework has been modified..."<<endl;
    FILE* stream=fopen("./main.cly","r");
    if(!stream){
        cout<<"Can not find Coly Main! Please check did you have install NicCent correctly."<<endl;
        return 2;
    }
    int c;
    string info="";
    while((c=fgetc(stream))!=-1){
        info+=char(c);
    }
    fclose(stream);
    if(GXPass::compile(info)==NICCENTMAINHASH) system("C:\\Coly\\Coly.exe main.cly");
    else{
        cout<<"The Coly Framework has been modified, startup aborted."<<endl;
        return 3;
    }
    return 0;
}
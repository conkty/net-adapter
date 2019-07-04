#pragma once

#include <cstdio>
#include <string>
#include <list>
#include "NetAdapter/NetAdapter.h"

#ifdef _WIN32
#include <Winsock2.h>
WSADATA wsaData;
void InitNetworking() {
	// Init Winsock2 //
	WSAStartup( MAKEWORD(2,2), &wsaData );
	atexit( (void(*)())WSACleanup );
}
#else // _WIN32 //
void InitNetworking() { }
#endif // _WIN32 //


struct AdapterInfo {
    std::string name = "";
    std::string ip = "";
    std::string netmask = "";
    std::string broadcast = "";
    std::string mac = "";
};

AdapterInfo primary_adapter();
std::list<AdapterInfo> all_adapter();
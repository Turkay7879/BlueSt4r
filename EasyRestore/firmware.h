#ifndef firmware
#define firmware

#include <string>
#include <stdio.h>
#include <Windows.h>
#include <shellapi.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

using namespace std;

string get_firmware_link(const string& version);
void version_control(const string& version);

#endif

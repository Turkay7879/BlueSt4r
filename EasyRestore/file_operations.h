#ifndef file_operations
#define file_operations

#include <tchar.h>
#include <ShlObj.h>
#include <Windows.h>
#include <fstream>
#include <string>

string desktop_file_path();
void delete_file(const string& file);
void check_leftovers();

#endif // !file_operations


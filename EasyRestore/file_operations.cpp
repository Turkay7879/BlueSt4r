#include "file_operations.h"
#include <iostream>

using namespace std;

string desktop_file_path() {
    wchar_t* desktop = nullptr;
    HRESULT hr = SHGetKnownFolderPath(
        FOLDERID_Desktop,
        0,
        nullptr,
        &desktop);

    if (SUCCEEDED(hr)) {
        wstring ws(desktop);
        string path(ws.begin(), ws.end());
        return path;
    }
    else {
        cerr << "Could not get Desktop file path.." << endl;
        system("pause");
        exit(ERROR);
    }
}
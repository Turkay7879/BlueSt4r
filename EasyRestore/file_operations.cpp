#include "file_operations.h"
#include <iostream>

using namespace std;

const string futurerestore = desktop + "\\futurerestore.exe";
const string ipsw = desktop + "\\ipsw.ipsw";
const string signature_hash = desktop + "\\blob.shsh2";
const string bb = desktop + "\\baseband.bbfw";
const string sep = desktop + "\\sep.im4p";
const string buildmanifest = desktop + "\\buildmanifest.plist";

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
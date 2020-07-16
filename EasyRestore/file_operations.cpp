#include "file_operations.h"
#include <iostream>

using namespace std;

const string futurerestore = desktop + "\\futurerestore.exe";
const string ipsw = desktop + "\\ipsw.ipsw";
const string signature_hash = desktop + "\\blob.shsh2";
const string bb = desktop + "\\baseband.bbfw";
const string sep = desktop + "\\sep.im4p";
const string buildmanifest = desktop + "\\buildmanifest.plist";
const string zip_file = desktop + "\\fr.zip";
const string run_path = desktop + "\\run.bat";

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

void delete_file(const string& file) {
    if (remove(file.c_str()) == 0) cout << "Leftover removed successfully!" << endl;
    else cout << "Deleting leftover failed! You may need to delete them manually from your Desktop." << endl;
}

void check_leftovers() {
    if (file_exist(sep)) delete_file(sep);
    if (file_exist(bb)) delete_file(bb);
    if (file_exist(buildmanifest)) delete_file(buildmanifest);
    if (file_exist(futurerestore)) delete_file(futurerestore);
    if (file_exist(run_path)) delete_file(run_path);
}
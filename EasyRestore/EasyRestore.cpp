#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <urlmon.h>
#include <shellapi.h>
#include "firmware.cpp"
#include "file_operations.cpp"

#pragma comment(lib, "urlmon.lib")

using namespace std;

const string futurerestore_url = "https://github.com/s0uthwest/futurerestore/releases/download/245/futurerestore_win64_v245.zip";
const string zip_file = desktop + "\\fr.zip";


void remove_leftover(string file) {
    if (remove(file.c_str()) == 0) cout << "Leftovers are removed successfully!" << endl;
    else cout << "Deleting leftovers failed! You may need to delete them manually." << endl;
}

void download(const string& version) {
    if (file_exist(futurerestore) == false) {
        wstring url_temp = wstring(futurerestore_url.begin(), futurerestore_url.end());
        LPCWSTR url = url_temp.c_str();

        wstring dir_temp = wstring(zip_file.begin(), zip_file.end());
        LPCWSTR destination = dir_temp.c_str();

        cout << "Downloading futurerestore... " << endl;
        HRESULT hr = URLDownloadToFile(NULL, url, destination, 0, NULL);
        if (hr != 0) {
            cerr << "Futurerestore download failed! Aborting.." << endl;
            system("pause");
            exit(ERROR);
        }
    }
    else
        cout << "Futurerestore already exists on desktop, continuing.." << endl;
    if (file_exist(ipsw) == false) {
        string download_link = get_firmware_link(version);
        wstring url_temp = wstring(download_link.begin(), download_link.end());
        LPCWSTR url = url_temp.c_str();

        wstring dir_temp = wstring(ipsw.begin(), ipsw.end());
        LPCWSTR destination = dir_temp.c_str();

        cout << "Downloading iOS " << version << " for iPhone 5s... " << endl;
        HRESULT hr = URLDownloadToFile(NULL, url, destination, 0, NULL);
        if (file_exist(ipsw) == true)
            cout << "iOS " << version << " firmware file for iPhone 5s is downloaded, continuing.." << endl;
        else {
            cerr << "Firmware file download failed! Aborting.." << endl;
            system("pause");
            exit(ERROR);
        }
    }
    else
        cout << "Firmware file already exists on desktop, continuing.." << endl;
}

void prep(const string& version) {

    ofstream exec(desktop + "\\run.bat");
    exec << "cd C:\\Program Files\\7-Zip" << "\n7z e " << "\"" << zip_file << "\"" << " -o\\" << desktop << "\"";
    
    if (!(version == "10.2" || version == "10.2.1" || version == "10.3" || version == "10.3.1" || version == "10.3.2" || version == "10.3.3")) {
        exec << "\ncd " << desktop << endl;
        exec << futurerestore << " -t " << signature_hash << " --latest-sep --latest-baseband " << ipsw << endl;
        exec << "pause" << endl;
        exec.close();
    }
    else {
        exec << "\ncd " << desktop << endl;
        exec << futurerestore << " -t " << signature_hash << " -b " << bb << " -p " << buildmanifest << " -s " << sep << " -m " << buildmanifest << " " << ipsw << endl;
        exec << "pause" << endl;
        exec.close();
    }
    ostream flush();
    cout << "Preparation is done!" << endl;
}

void run() {

    string run = desktop + "\\run.bat";
    ShellExecuteA(
        0,
        "open",
        run.c_str(),
        NULL,
        NULL,
        SW_SHOW);
    system("pause");

    remove_leftover(run);
    remove_leftover(zip_file);
    remove_leftover(futurerestore);
}

int main()
{
    string version;
    cout << "Which version you'd like to restore (Enter it like \"10.2\", \"12.1.1\" etc. without quotes): ";
    getline(cin, version);

    version_control(version);
    prep(version);
    download(version);
    run();

    system("pause");
    return 0;
}

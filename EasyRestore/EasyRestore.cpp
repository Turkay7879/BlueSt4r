#include "firmware.cpp"
#include "file_operations.cpp"

using namespace std;

void download(const string& version) {
    if (file_exist(futurerestore) == false) {
        wstring url_temp = wstring(futurerestore_link.begin(), futurerestore_link.end());
        LPCWSTR url = url_temp.c_str();

        wstring dir_temp = wstring(zip_file.begin(), zip_file.end());
        LPCWSTR destination = dir_temp.c_str();

        cout << "Downloading futurerestore... " << endl;
        HRESULT hr = URLDownloadToFile(NULL, url, destination, 0, NULL);
        if (!SUCCEEDED(hr)) {
            cerr << "Futurerestore download failed! Aborting.." << endl;
            check_leftovers();
            system("pause");
            exit(ERROR);
        }
    }
    else cout << "Futurerestore already exists on desktop, continuing.." << endl;

    if (file_exist(ipsw) == false) {
        string download_link = get_firmware_link(version);
        wstring url_temp = wstring(download_link.begin(), download_link.end());
        LPCWSTR url = url_temp.c_str();

        wstring dir_temp = wstring(ipsw.begin(), ipsw.end());
        LPCWSTR destination = dir_temp.c_str();

        cout << "Downloading iOS " << version << " for iPhone 5s... " << endl;
        HRESULT hr = URLDownloadToFile(NULL, url, destination, 0, NULL);
        if (SUCCEEDED(hr))
            cout << "iOS " << version << " firmware file for iPhone 5s is downloaded, continuing.." << endl;
        else {
            cerr << "Firmware file download failed! Aborting.." << endl;
            delete_file(zip_file);
            check_leftovers();
            system("pause");
            exit(ERROR);
        }
    }
    else
        cout << "Firmware file already exists on desktop, continuing.." << endl;
}

void prep(const string& version) {

    ofstream run(run_path);
    run << "cd C:\\Program Files\\7-Zip" << "\n7z e " << "\"" << zip_file << "\"" << " -o" << desktop << "\"" << endl;
    
    if (!(version == "10.2" || version == "10.2.1" || version == "10.3" || version == "10.3.1" || version == "10.3.2" || version == "10.3.3")) {
        run << futurerestore << " -t " << signature_hash << " --latest-sep --latest-baseband " << ipsw << endl;
        run << "pause" << endl;
        run.close();
    }
    else {
        run << futurerestore << " -t " << signature_hash << " -b " << bb << " -p " << buildmanifest << " -s " << sep << " -m " << buildmanifest << " " << ipsw << endl;
        run << "pause" << endl;
        run.close();
    }
    ostream flush();

    if (!file_exist(run_path)) {
        cerr << "Run command could not be created, aborting.." << endl;
        check_leftovers();
        system("pause");
        exit(ERROR);
    }
    else cout << "Preparation is done!" << endl;
}

void run() {
    ShellExecuteA(
        0,
        "open",
        run_path.c_str(),
        NULL,
        NULL,
        SW_SHOW);
    check_leftovers();
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

#include <iostream>
#include "firmware.h"
#include "file_operations.h"

using namespace std;

const string desktop = desktop_file_path();

bool file_exist(const string& file) {
	struct stat buffer;
	return (stat(file.c_str(), &buffer) == 0);
}

void version_control(const string& version) {
	if (version == "10.2" || version == "10.2.1" || version == "10.3" ||
		version == "10.3.1" || version == "10.3.2" || version == "10.3.3") {
		cout << "\nBefore starting, make sure to have iTunes installed on your computer (Not the one from MS Store)";
		cout << "Since you're restoring to 10.2 - 10.3.3, some additional files will be downloaded." << endl;
		cout << "Don't forget that this process is going to completely RESET your device, so make sure to back your data up first!";
		cout << "\n\nWhen you're ready to begin, just press enter on your keyboard.." << endl;
		system("pause");
		ostream flush();

		if (file_exist(desktop + "\\buildmanifest.plist") == false) {
			const string buildmanifest_link = "https://gitlab.com/devluke/stablea7/raw/master/A7_10.3.3_OTA_Manifests.zip";
			wstring download_buildmanifest = wstring(buildmanifest_link.begin(), buildmanifest_link.end());
			LPCWSTR url = download_buildmanifest.c_str();

			const string destination = desktop + "\\buildmanifest_zip.zip";
			wstring location = wstring(destination.begin(), destination.end());
			LPCWSTR download_location = location.c_str();

			cout << "Downloading BuildManifest.. " << endl;
			HRESULT hr = URLDownloadToFile(NULL, url, download_location, 0, NULL);
			if (!SUCCEEDED(hr)) {
				cerr << "Could not download BuildManifest file required for restore process, aborting.. " << endl;
				system("pause");
				exit(ERROR);
			}
			else {
				cout << "Grabbing the correct BuildManifest file, please DON'T touch anything.. " << endl;
				ofstream temp(desktop + "\\extract_plist.bat");
				temp << "mkdir " << desktop << "\\files\\" << endl;
				temp << "cd C:\\Program Files\\7-Zip" << "\n7z e " << desktop << "\\buildmanifest_zip.zip -o" << desktop << "\\files\\" << endl;
				temp << "cd " << desktop << "\\files\\" << endl;
				temp << "move \"BuildManifest_iPhone6,2_1033_OTA.plist\" \"" << desktop << "\\buildmanifest.plist\"" << endl;
				temp << "cd " << desktop << "\\" << endl;
				temp << "rd /S /Q files\\" << endl;
				temp << "del buildmanifest_zip.zip" << endl;
				temp.close();

				string* file = new string(desktop + "\\extract_plist.bat");
				ShellExecuteA(
					0,
					"open",
					file->c_str(),
					NULL,
					NULL,
					SW_HIDE);

				remove(file->c_str());
				delete file;
			}
			ostream flush();
		}
		else cout << "BuildManifest already exists on Desktop, continuing.. " << endl;

		if (file_exist(desktop + "\\sep.im4p") == false) {
			wstring sep_link_toconvert = wstring(sep_link.begin(), sep_link.end());
			LPCWSTR sep_dl = sep_link_toconvert.c_str();

			const string sep_file = desktop + "\\sep.im4p";
			wstring sep_destination_toconvert = wstring(sep_file.begin(), sep_file.end());
			LPCWSTR sep_destination = sep_destination_toconvert.c_str();

			cout << "Downloading SEP.." << endl;
			HRESULT res_sep = URLDownloadToFile(NULL, sep_dl, sep_destination, 0, NULL);
			if (file_exist(desktop + "\\sep.im4p") == false) {
				cerr << "Downloading SEP failed, aborting.." << endl;
				delete_file(desktop + "\\buildmanifest.plist");
				system("pause");
				exit(ERROR);
			}
		}
		else cout << "SEP already exists on Desktop, continuing.. " << endl;

		if (file_exist(desktop + "\\baseband.bbfw") == false) {
			wstring bb_link_toconvert = wstring(bb_link.begin(), bb_link.end());
			LPCWSTR bb_dl = bb_link_toconvert.c_str();

			const string bb_file = desktop + "\\baseband.bbfw";
			wstring bb_destination_toconvert = wstring(bb_file.begin(), bb_file.end());
			LPCWSTR bb_destination = bb_destination_toconvert.c_str();

			cout << "Downloading Baseband.." << endl;
			HRESULT res_bb = URLDownloadToFile(NULL, bb_dl, bb_destination, 0, NULL);
			if (!SUCCEEDED(res_bb)) {
				cerr << "Downloading baseband failed, aborting.." << endl;
				delete_file(desktop + "\\buildmanifest.plist");
				delete_file(desktop + "\\sep.im4p");
				system("pause");
				exit(ERROR);
			}
		}
		else cout << "Baseband already exists on Desktop, continuing.. " << endl;
	}
	else if (!(version == "11.3" || version == "11.3.1" || version == "11.4" || version == "11.4.1" ||
		version == "12.0" || version == "12.0.1" || version == "12.1" || version == "12.1.1" ||
		version == "12.1.2" || version == "12.1.3" || version == "12.1.4" || version == "12.2" ||
		version == "12.3" || version == "12.3.1" || version == "12.4" || version == "12.4.1" ||
		version == "12.4.2" || version == "12.4.3" || version == "12.4.4" || version == "12.4.5" ||
		version == "12.4.6" || version == "12.4.7" || version == "12.4.8")) {
		cerr << "Invalid iOS version, aborting.." << endl;
		system("pause");
		exit(ERROR);
	}
	else {
		cout << "Restore will be processed with latest SEP and Baseband available" << endl;
		cout << "If you're restoring to 11.3 - 11.4.1 or 12.2 - 12.4.7, restore should be fine";
		cout << "\nBefore starting, make sure to have iTunes installed on your computer (Not the one from MS Store)";
		cout << "\n\nWARNING: iOS 12.0 - 12.1.4 versions with latest SEP and Baseband have the Fortnight bug, ";
		cout << "if you're NOT aware of this and trying to restore to iOS 12.0 - 12.1.4, you should either reconsider it or ";
		cout << "make sure to NOT setup Touch ID and Passcode at initial setup of your iPhone after restoring it.";
		cout << "\nDon't forget that this process is going to completely RESET your device, so make sure to back your data up first!";
		cout << "\n\nWhen you're ready to begin, just press enter on your keyboard.." << endl;
		system("pause");
	}
}

string get_firmware_link(const string& version) {
	if (version == "10.2")				return iOS_10_2;
	else if (version == "10.2.1")			return iOS_10_2_1;
	else if (version == "10.3")			return iOS_10_3;
	else if (version == "10.3.1")			return iOS_10_3_1;
	else if (version == "10.3.2")			return iOS_10_3_2;
	else if (version == "10.3.3")			return iOS_10_3_3;
	else if (version == "11.3")			return iOS_11_3;
	else if (version == "11.3.1")			return iOS_11_3_1;
	else if (version == "11.4")			return iOS_11_4;
	else if (version == "11.4.1")			return iOS_11_4_1;
	else if (version == "12.0")			return iOS_12_0;
	else if (version == "12.0.1")			return iOS_12_0_1;
	else if (version == "12.1")			return iOS_12_1;
	else if (version == "12.1.1")			return iOS_12_1_1;
	else if (version == "12.1.3")			return iOS_12_1_3;
	else if (version == "12.1.4")			return iOS_12_1_4;
	else if (version == "12.2")			return iOS_12_2;
	else if (version == "12.3")			return iOS_12_3;
	else if (version == "12.3.1")			return iOS_12_3_1;
	else if (version == "12.4")			return iOS_12_4;
	else if (version == "12.4.1")			return iOS_12_4_1;
	else if (version == "12.4.2")			return iOS_12_4_2;
	else if (version == "12.4.3")			return iOS_12_4_3;
	else if (version == "12.4.4")			return iOS_12_4_4;
	else if (version == "12.4.5")			return iOS_12_4_5;
	else if (version == "12.4.6")			return iOS_12_4_6;
	else if (version == "12.4.7")			return iOS_12_4_7;
	else if (version == "12.4.8")			return iOS_12_4_8;
	else if (version == "12.1.2") {
		cout << "Which build number do you have SHSH for? 16C101 or 16C104: ";
		string build_num;
		getline(cin, build_num);
		if (build_num == "16C101")		return iOS_12_1_2_101;
		else if (build_num == "16C104")		return iOS_12_1_2_104;
		else {
			cerr << "Invalid build number, quitting.. " << endl;
			system("pause");
			exit(ERROR);
		}
	}
}

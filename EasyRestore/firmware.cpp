#include "firmware.h"
#include <iostream>
#include <string>
#include "file_operations.h"

using namespace std;

const string iOS_10_2 = "http://appldnld.apple.com/ios10.2seed/031-93643-20161207-6173C962-BBD8-11E6-B93D-977FE47229E1/iPhone_4.0_64bit_10.2_14C92_Restore.ipsw";
const string iOS_10_2_1 = "http://appldnld.apple.com/ios10.2.1/031-96807-20170112-6155686C-D81D-11E6-BDB8-FB01D55B5B9D/iPhone_4.0_64bit_10.2.1_14D27_Restore.ipsw";
const string iOS_10_3 = "http://appldnld.apple.com/ios10.3/091-02949-20170327-7584B286-0D86-11E7-A4FA-7ECE122AC769/iPhone_4.0_64bit_10.3_14E277_Restore.ipsw";
const string iOS_10_3_1 = "http://appldnld.apple.com/ios10.3.1/091-06776-20170403-3AFEBEE0-16E1-11E7-B7AE-1D4C132AC769/iPhone_4.0_64bit_10.3.1_14E304_Restore.ipsw";
const string iOS_10_3_2 = "http://appldnld.apple.com/ios10.3.2/031-98771-20170515-E1F8ADA4-2F92-11E7-B86F-ED688FB7FE33/iPhone_4.0_64bit_10.3.2_14F89_Restore.ipsw";
const string iOS_10_3_3 = "http://appldnld.apple.com/ios10.3.3/091-23133-20170719-CA8E78E6-6977-11E7-968B-2B9100BA0AE3/iPhone_4.0_64bit_10.3.3_14G60_Restore.ipsw";
const string iOS_11_3 = "http://appldnld.apple.com/ios11.3/091-40386-20180329-37989C86-2968-11E8-BC8B-ECBDE6893228/iPhone_4.0_64bit_11.3_15E216_Restore.ipsw";
const string iOS_11_3_1 = "http://updates-http.cdn-apple.com/2018/ios/091-78138-20180419-8890F634-4023-11E8-A0E9-41A7FBE594B0/iPhone_4.0_64bit_11.3.1_15E302_Restore.ipsw";
const string iOS_11_4 = "http://updates-http.cdn-apple.com/2018/ios/091-64669-20180529-3B06872A-5ABE-11E8-856C-E557A3E35D9E/iPhone_4.0_64bit_11.4_15F79_Restore.ipsw";
const string iOS_11_4_1 = "http://updates-http.cdn-apple.com/2018/ios/091-74856-20180709-813FF9AE-7C1C-11E8-8A6E-A95B544C24EB/iPhone_4.0_64bit_11.4.1_15G77_Restore.ipsw";
const string iOS_12_0 = "http://updates-http.cdn-apple.com/2018FallFCS/fullrestores/091-63009/116F8BD8-AC8E-11E8-A3AF-9B7076D145D8/iPhone_4.0_64bit_12.0_16A366_Restore.ipsw";
const string iOS_12_0_1 = "http://updates-http.cdn-apple.com/2018FallFCS/fullrestores/041-09290/34963678-C5EA-11E8-AE7F-8224A7DA43E1/iPhone_4.0_64bit_12.0.1_16A404_Restore.ipsw";
const string iOS_12_1 = "http://updates-http.cdn-apple.com/2018FallFCS/fullrestores/091-91318/964164AA-D4BE-11E8-B0E4-880CD9066485/iPhone_4.0_64bit_12.1_16B92_Restore.ipsw";
const string iOS_12_1_1 = "http://updates-http.cdn-apple.com/2018FallFCS/fullrestores/041-05345/58661FD6-E9F9-11E8-BBEA-92BB56093B49/iPhone_4.0_64bit_12.1.1_16C50_Restore.ipsw";
const string iOS_12_1_2_101 = "http://updates-http.cdn-apple.com/2018FallFCS/fullrestores/041-27402/5EB2B9BC-FF0C-11E8-ADA7-AAA984486A64/iPhone_4.0_64bit_12.1.2_16C101_Restore.ipsw";
const string iOS_12_1_2_104 = "http://updates-http.cdn-apple.com/2018FallFCS/fullrestores/041-28432/A2A5A170-02EA-11E9-86D5-9A6E32F013F9/iPhone_4.0_64bit_12.1.2_16C104_Restore.ipsw";
const string iOS_12_1_3 = "http://updates-http.cdn-apple.com/2019WinterFCS/fullrestores/041-16709/7C7B2F86-15ED-11E9-A5E9-9755B489F907/iPhone_4.0_64bit_12.1.3_16D39_Restore.ipsw";
const string iOS_12_1_4 = "http://updates-http.cdn-apple.com/2019WinterFCS/fullrestores/041-39596/320D9284-292C-11E9-A180-4311412B0A59/iPhone_4.0_64bit_12.1.4_16D57_Restore.ipsw";
const string iOS_12_2 = "http://updates-http.cdn-apple.com/2019SpringFCS/fullrestores/041-06931/ECF5CC36-499F-11E9-BCDC-E44576CE070F/iPhone_4.0_64bit_12.2_16E227_Restore.ipsw";
const string iOS_12_3 = "http://updates-http.cdn-apple.com/2019SpringFCS/fullrestores/041-61719/B8E28B3A-71E2-11E9-AF97-0984412A1E9F/iPhone_4.0_64bit_12.3_16F156_Restore.ipsw";
const string iOS_12_3_1 = "http://updates-http.cdn-apple.com/2019SpringFCS/fullrestores/041-68637/CC464978-7C96-11E9-B311-4DF06256CCDB/iPhone_4.0_64bit_12.3.1_16F203_Restore.ipsw";
const string iOS_12_4 = "http://updates-http.cdn-apple.com/2019SummerFCS/fullrestores/041-86553/9E218350-A743-11E9-9805-B896964EA79A/iPhone_4.0_64bit_12.4_16G77_Restore.ipsw";
const string iOS_12_4_1 = "http://updates-http.cdn-apple.com/2019SummerFCS/fullrestores/061-05267/A4464F60-C4E7-11E9-A022-17610AD8B7A1/iPhone_4.0_64bit_12.4.1_16G102_Restore.ipsw";
const string iOS_12_4_2 = "http://updates-http.cdn-apple.com/2019SummerFCS/fullrestores/061-21348/FD35E13C-DC8C-11E9-8BDD-268C66A83945/iPhone_4.0_64bit_12.4.2_16G114_Restore.ipsw";
const string iOS_12_4_3 = "http://updates-http.cdn-apple.com/2019FallFCS/fullrestores/061-32377/2091C382-F0CC-11E9-8000-75BD38B10759/iPhone_4.0_64bit_12.4.3_16G130_Restore.ipsw";
const string iOS_12_4_4 = "http://updates-http.cdn-apple.com/2019FallFCS/fullrestores/061-38024/DEAC4414-0BFC-11EA-8CCC-6EFE7531BBAA/iPhone_4.0_64bit_12.4.4_16G140_Restore.ipsw";
const string iOS_12_4_5 = "http://updates-http.cdn-apple.com/2020WinterFCS/fullrestores/061-62196/E2C61737-55E3-45B6-BDCD-AF2968B5EB52/iPhone_4.0_64bit_12.4.5_16G161_Restore.ipsw";
const string iOS_12_4_6 = "http://updates-http.cdn-apple.com/2020WinterFCS/fullrestores/061-73609/7E12EF2A-B70C-4327-9EAC-5C28D62EA6AD/iPhone_4.0_64bit_12.4.6_16G183_Restore.ipsw";
const string iOS_12_4_7 = "http://updates-http.cdn-apple.com/2020SpringFCS/fullrestores/061-94832/B6D93224-1059-4DF0-9438-78CD3BED57FE/iPhone_4.0_64bit_12.4.7_16G192_Restore.ipsw";

const string bb_link = "https://raw.githubusercontent.com/wooozie69/BlueSt4r/master/iOS%2010%20SEP%20%2B%20BB/Mav7Mav8-7.60.00.Release.bbfw";
const string sep_link = "https://raw.githubusercontent.com/wooozie69/BlueSt4r/master/iOS%2010%20SEP%20%2B%20BB/sep-firmware.n53.RELEASE.im4p";

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
			if (file_exist(desktop + "\\buildmanifest_zip.zip") == false) {
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
		version == "12.4.6" || version == "12.4.7")) {
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

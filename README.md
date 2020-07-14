# BlueSt4r repository, project "EasyRestore"

EasyRestore is a entry-level project to test my C++ skills by making a console program.
The purpose of this console program is to make futurerestore process easier. 
Although it's "technically" working, it still has to be improved in order to make it more usable.
To find out what "futurerestore" is, check out s0uthwest's futurerestore project for purpose of EasyRestore (Huge thanks to him and may his soul rest in peace).

Current abilities of EasyRestore:
  1. Actually restores an iDevice (Only iPhone6,2 ATM)
  2. Downloads futurerestore by itself (s0uthwest's fork is used in this project, v245)
  3. Downloads firmware file (a.k.a. IPSW) by itself (Only from Apple's own servers. Firmware files are definitely NOT, and WON'T be downloaded by other matters or from sources)
  4. User get's to choose which iOS version to restore to (Only 10.2 - 10.3.3 and 11.3 - 12.4.7 versions are supported ATM, due to SEP compatibility)
  5. User ONLY needs to provide an SHSH2 blob in order to use EasyRestore (Although the generator in SHSH2 blob has to be set before restoring iDevice)

Known issues:
  1. In order to restore to 10.2 - 10.3.3; an OTA BuildManifest file, local baseband and local SEP has to be used, which EasyRestore can't ATM. (Tl;dr NO RESTORE to iOS 10)
  2. EasyRestore uses user's Desktop folder by default, but it uses a custom path instead of just finding user's Desktop path.

Dependencies:
  1. 7-Zip program should be installed before using this (Extracting purposes).
  2. Final program file is not included, so C++ and header files has to be compiled in an IDE (VS Community 2019 is used by myself)
  
Made by wooozie69  

# BlueSt4r repository, project "EasyRestore"

EasyRestore is a entry-level project to test my C++ skills by making a console program.
The purpose of this console program is to make futurerestore process easier. 
Although it's "technically" working, it still has to be improved in order to make it more usable.
To find out what "futurerestore" is, check out s0uthwest's futurerestore project for purpose of EasyRestore (Huge thanks to him and may his soul rest in peace).

Current abilities of EasyRestore:
  1. Actually restores an iDevice (Only iPhone6,2 ATM)
  2. Downloads futurerestore by itself (s0uthwest's fork is used in this project, v245)
  3. Downloads firmware file (a.k.a. IPSW) by itself (Only from Apple's own servers. IPSW files are definitely NOT, and WON'T be downloaded from other sources)
  4. User get's to choose which iOS version to restore to (Only 10.2 - 10.3.3 and 11.3 - 12.4.7 versions are supported ATM, due to SEP compatibility)
  5. User ONLY needs to provide an SHSH2 blob in order to use EasyRestore (Although the generator in SHSH2 blob has to be set before restoring iDevice)

Dependencies:
  1. 7-Zip program should be installed before using this (Extracting purposes).
  2. Final program file is not included, so C++ and header files has to be compiled in an IDE (VS Community 2019 is used by myself)
  
Made by wooozie69  

# Project "EasyRestore"

EasyRestore is a entry-level project to test my C++ skills by making a console program.
The purpose of this console program is to make futurerestore process easier. 
Although it's "technically" working, it still has to be improved in order to make it more usable.
To find out what "futurerestore" is, check out s0uthwest's futurerestore project for purpose of EasyRestore (Huge thanks to him and may his soul rest in peace).

# Current abilities of EasyRestore:
  1. Actually restores an iDevice (Only iPhone6,2 ATM)
  2. Downloads futurerestore by itself (s0uthwest's fork is used in this project, v245)
  3. Downloads firmware file (a.k.a. IPSW) by itself (Only from Apple's own servers. IPSW files are definitely NOT, and WON'T be downloaded from other sources)
  4. Supported iOS versions to restore:
      - iOS 10.2 - 10.3.3
      - iOS 11.3 - 11.4.1
      - iOS 12.0 - 12.1.4 (Warning: Fortnight bug, NOT recommended to restore to)
      - iOS 12.2 - 12.4.8
  5. User ONLY needs to provide an SHSH2 blob in order to use EasyRestore (Although the generator in SHSH2 blob has to be set before restoring iDevice)

# Dependencies:
  1. 7-Zip program should be installed before using this (Extracting purposes).
  
# How to use:
  1. If you only have your SHSH2 blob, just rename it to "blob.shsh2" and place it to your Desktop. Then run EasyRestore, that's it. Necessary files will be downloaded for you.
  2. If you have other files such as IPSW, Baseband or SEP; just place them to your Desktop and rename them as "ipsw.ipsw", "baseband.bbfw", "sep.im4p" and run EasyRestore.
  
# Notes:
  - EasyRestore uses Desktop as working directory, so while it's running, you might see files (SEP, Baseband, IPSW, futurerestore etc.) that weren't there before. 
  - If you'd like to try yourself, you can always test the code on an IDE (I've used VS Community 2019) and see for yourself. 
  - SEP and Baseband files are directly downloaded on this (BlueSt4r) repo, and they're originally extracted from iOS 10.3.3 IPSW. Reason for that is that neither extracting them remotely, nor downloading the whole 10.3.3 IPSW were reliable or effective options to do so.
 
# Thanks to:
  - s0uthwest
  
Made by wooozie69  

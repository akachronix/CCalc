#!/bin/sh

RED='\033[0;31m'
NC='\033[0m'

sudo sh compile.sh

echo "[${RED}LOG${NC}] Moving libmath shared library into standard directory."
sudo cp bin/libmath.so /usr/lib/libmath.so
sudo chmod 755 /usr/lib/libmath.so

echo "[${RED}LOG${NC}] Moving shared library into standard directory."
sudo cp bin/liblog.so /usr/lib/liblog.so
sudo chmod 755 /usr/lib/liblog.so

echo "[${RED}LOG${NC}] Moving binary into standard directory."
sudo cp bin/ccalc /usr/bin

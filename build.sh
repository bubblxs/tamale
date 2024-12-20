#!/bin/bash

APPIDS_PATH="./ids.txt";

if [ ! -f $APPIDS_PATH ]; then
    touch $APPIDS_PATH;
fi

# sudo cp libsteam_api.so /lib/x86_64-linux-gnu

g++ tamale.cpp -I steam -L. -lsteam_api -o tamale.1
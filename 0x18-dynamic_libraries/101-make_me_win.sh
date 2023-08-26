#!/bin/bash
gcc shared -o myprint.so -fPIC test.c
export LD_PRELOAD=./myprintf.ao:$LD_LIBRARY_PATH

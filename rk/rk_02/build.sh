#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Wvla -o app.exe main.c get_words.c write_file.c


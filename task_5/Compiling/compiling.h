#ifndef COMPILING_H
#define COMPILING_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../../task_4/stack.cpp"

const char *SRC_FILE = "fnames.txt";
const char *OUTPUT_FILE = "fnumbers.txt";

const char *COMMANDS[] = {"push", "add", "sub", "div", "out"};

const int MAX_LINE_LEN = 8;

#endif
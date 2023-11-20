#ifndef ONEGIN_H
#define ONEGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// PascalStyle
// snake_style
// camelStyle
// UPPERCASE_STYLE

const int MAX_LINE_LEN = 100;

long GetFileSize (FILE* file);

char** FileReader (FILE* file);

int mystrcmp (const char* str1, const char* str2);

int Comparator (const void* el1, const void* el2); // обобщенный компаратор

void Swap (void* el1, void* el2); // копирование данных побайтово

void Sort (void* arr, int nel, int elem_size, int (*Comparator)(const void*, const void*));

#endif // ONEGIN_H
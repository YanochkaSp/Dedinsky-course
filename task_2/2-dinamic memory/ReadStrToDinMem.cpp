#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const size_t NUM_LINES = 10;
const size_t NUM_COLS = 10;
const int MAX_LINE_LEN = 500;

// функция strcpy
void StringCopy(char* str1, char* str2) // аналогично: char str1[], char str2[]
{
    // не будем передавать размер строки
    for (size_t i = 0; ;i++)
    {
        str1[i] = str2[i]; // копируем str2 в str1 
        if (str2[i] == 0) // если строка 'закончилась'
            break;
    }
}

int main(int argc, char* argv[])
{
    FILE* fileOnrgin = fopen("Reading.txt", "r");
    char* arrPointer[NUM_LINES] = {}; // указатель на массив из указателей
    for (size_t j = 0; j < NUM_COLS; j++)
    {
        char string[MAX_LINE_LEN] = {};
        fgets(string, sizeof(char) * MAX_LINE_LEN, fileOnrgin);
        int strsize = strlen(string); // длина считанной строки
        char* strMem = (char*)calloc(strsize+1, sizeof(char));
        StringCopy(strMem, string);
        arrPointer[j] = strMem;
        
        printf("%s", string);
    }

    fclose(fileOnrgin);

    for (size_t i = 0; i < NUM_LINES; i++)
        free(arrPointer[i]);
}
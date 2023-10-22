// fixed memory

#include <stdio.h>
#include <string.h>

const size_t NUMLINES = 10;
const size_t NUMCOLS = 10;

int main(int argc, char* argv[])
{
    FILE* fileOnegin = fopen("Reading.txt", "r");
    char data[NUMLINES][NUMCOLS] = {};
    for (size_t i = 0; i < NUMLINES; i++)
    {
        // printf("[%lu]", i);
        if (fgets(data[i], sizeof(char) * sizeof(data[0]), fileOnegin) == NULL)
            break;
        printf("%s", data[i]);
    }
    fclose(fileOnegin);
}

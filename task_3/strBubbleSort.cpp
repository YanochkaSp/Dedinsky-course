#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LINE_LEN = 100;
const int MAX_LINE_NUM = 100;

long GetFileSize(FILE* file)
{
    fseek(file, 0, SEEK_END);
    long FileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    return FileSize;
}

char* FileReader(FILE* file)
{
    long FileSize = GetFileSize(file);
    char* lines = (char*)calloc(FileSize+1, sizeof(char));
    // if (fread(mem_buf, sizeof(char)*MAX_LINE_LEN, file) != FileSize) 
    //     puts("Reading error", stderr);
    // char lines[MAX_LINE_NUM][MAX_LINE_LEN];
    int count = 0;
    while (fgets(lines, sizeof(char)*MAX_LINE_LEN, file) != NULL)
    {
        printf("%c", lines[count]);
        count++;
    }
    printf("\n%d lines at all\n", count);
    return lines;
}

int StringComparator(void* lhs, void* rhs) // обертка функции
{
    return strcmp((char*)lhs, (char*)rhs);
}

// для поиска \n использовать strchr

void StringComparator(char buf[][], int nlines)
{
    for (int row = 0; row < nlines; row++)
    {
        for (int col = 0; ; col++)
        {
            printf("Start comparing");
            if (buf[row][col] < buf[row+1][col])
            {
                printf("%c is earlier than %c\n", buf[row][col], buf[row+1][col]);
                // char temp

            }
        }   
    }
}

int main(int argc, char* argv[])
{
    FILE* Input = fopen("Input.txt", "r");
    char* lines = FileReader(Input);
    int count = sizeof(lines[count])/sizeof(char);
    StringComparator(lines, count, Input);

    fclose(Input);
}
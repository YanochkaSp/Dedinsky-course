#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

long GetFileSize(FILE* file)
{
    fseek(file, 0, SEEK_END); 
    long FileSize = ftell(file); // определение размера файла в байтах
    fseek(file, 0, SEEK_SET);  // или rewind

    return FileSize;
}

int main(int argc, char* argv[])
{
    FILE* fileOnegin = fopen("Reading.txt", "r");
    if (fileOnegin == NULL)
    {
        // puts("Openning error");
        printf("errno: %d\n",errno);
        perror("fileOnegin");
    } 

    long FileSize = GetFileSize(fileOnegin);
    printf("FileSize = %ld\n", FileSize);

    char* mem_buf = (char*)calloc(FileSize+1, sizeof(char));
    if (mem_buf == NULL) puts("Memory allocation error");

    int num_n = 0;

    if (fread(mem_buf, sizeof(char), FileSize, fileOnegin) != FileSize) // возвращает количество считанных символов
        fputs("Reading error", stderr);

    int i = 0;
    while (mem_buf[i] != '\0') 
    {
        if (mem_buf[i] == '\n')
        {
            mem_buf[i] = '\0';
            num_n++;
        }
        i++;
    }
    
    char** LinesPointer = (char**)calloc(num_n+1, sizeof(char*));
    LinesPointer[0] = mem_buf;
    size_t j = 1;
    for (size_t i = 0; i < FileSize; i++)
    {
        if (mem_buf[i] == '\0')
        {
            LinesPointer[j] = mem_buf+i+1;
            j++;
        }
        
    }
    for (int i = 0; i < num_n+1; i++)
    {
        puts(LinesPointer[i]);
    }

// printf("num_n = %d\n", num_n);

    
    printf("num_n = %d\n", num_n);

    fclose(fileOnegin);

    free(LinesPointer);
    free(mem_buf);

    return 0;
}
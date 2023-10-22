// сделать стандартную обертку

#include <stdio.h>
#include <string.h>
#include <errno.h>

const size_t NUMLINES = 10;
const size_t NUMCOLS = 10;

int main(int argc, char* argv[])
{
    FILE* fileOnegin = fopen("Reading.txt", "r");
    if (fileOnegin == NULL)
    {
        // puts("Openning error");
        printf("errno1: %d\n", errno);
        return 1;
    }

    char data[NUMLINES][NUMCOLS] = {};  //'{}' - для того, чтобы массив инициализировался нулями
    for (size_t i = 0; i < NUMLINES; i++)
    {
        char symb = '0';
        size_t j = 0;
        while (symb != '\n')  // пока не конец строки
        {
            // fscanf(fileOnegin, "%c", &symb);
            if (fscanf(fileOnegin, "%c", &symb) == EOF)
            {
                puts("fscanf error");
                printf("errno2: %d\n", errno);
                return 1;
            }  
            data[i][j] = symb;
            j++;
            printf("%c", symb);
            if (symb == EOF)
                break;  
        }
    }
    if (fclose(fileOnegin) == EOF)
    {
        puts("Closing error");
        printf("error3: %d\n", errno);
        return 1;
    }

    return 0;
}
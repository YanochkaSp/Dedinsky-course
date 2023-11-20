#include "Onegin.h"

int main (int argc, char* argv[])
{
    FILE* file = fopen("Input.txt", "r");
    long FileSize = GetFileSize(file);
    char** arrPointer = FileReader(file);
    fclose(file);
    // BubbleSort(arrPointer, FileSize+1);
    Sort(arrPointer, FileSize + 1, sizeof(char*), Comparator);

    // for (int i = 0; i < FileSize + 1; i++)
    // {
    //     printf("%s", arr[i]);
    // }
    free(arrPointer);

    // for (int i = 0; i < FileSize, i++)
    // {

    // }

    return 0;
}

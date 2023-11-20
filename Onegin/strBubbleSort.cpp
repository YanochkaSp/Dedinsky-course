#include "Onegin.h"

// long GetFileSize (FILE* file) // СОХРАНИТЬ ПОЗИЦИЮ УКАЗАТЕЛЯ
// {
//     long FileSize = ftell(file);
//     fseek(file, 0, SEEK_SET);
//     return FileSize;
// }

long GetFileSize (FILE* file)
{
    long curPos = ftell(file); // сохраняем текущую позицию указателя
    fseek(file, 0, SEEK_END); // перемещаем указатель файла в конец
    long fileSize = ftell(file); // получаем размер файла
    fseek(file, curPos, SEEK_SET); // возвращаемся на сохраненную позицию
    return fileSize;
}

char** FileReader (FILE* file)
{
    long FileSize = GetFileSize(file);
    char* mem_buf = (char*)calloc(FileSize + 1, sizeof(char));
    if (fread(mem_buf, sizeof(char), FileSize, file) != FileSize) 
        fprintf(stderr, "Reading error\n"); 
    
    int count = 0;
    for ( ; count < FileSize + 1; count++)
    {
        if (strchr(mem_buf, '\n') != NULL) 
            printf("\\n founded\n"); 
        *(mem_buf+count) = '\0'; // <-> mem_buf[i] = 0
    }

    char** arrPointer = (char**)calloc(count + 1, sizeof(char*)); // if there wasn't '\n' at the end (array of pointers)
    int LineLen = 0;
    for (int i = 0; i < count; i++)
    {
        LineLen++;
        if (mem_buf[i] == '\n')
        {
            arrPointer[i] = mem_buf + LineLen + 1;
        }
    }

    return (arrPointer);
}

int mystrcmp (const char* str1, const char* str2)
{
    int pos = 0;
    while(str1[pos] != '\0' && str2[pos] != '\0' && str1[pos] == str2[pos])
    {
        pos++;
    } 
    return str1[pos] - str2[pos];
}

// void BubbleSort (char* arr[], int size)
// {
//     for (int pass; pass < size-1; pass++)
//     {
//         for (int i = 0; i < size-pass-1; i++)
//         {
//             assert(0<=i && i<size);
//             assert(0<=i+1 && i+1<size);
//             if (mystrcmp(arr[i], arr[i+1]) > 0)
//             {
//                 char* temp = arr[i];
//                              arr[i] = arr[i+1];
//                                       arr[i+1] = temp;
//             }
//         }
//     }
// }

int Comparator (const void* el1, const void* el2) // обобщенный компаратор
{
    return mystrcmp (*(const char**)el1, *(const char**)el2);
}

// Swap() написать жадным алгоритмом
// Swap() написать побитово
void Swap (void* el1, void* el2, int elsize) // побайтово
{
    char* elem1 = (char*)el1;
    char* elem2 = (char*)el2;

    char temp = '\0';
    
    for (int i = 0; i < elsize; i++)
    {
        temp = *elem1;
               *elem1 = *elem2;
                        *elem2 = temp;
        elem1++;
        elem2++;   
    }   
}

void GreedSwap (void* el1, void* el2, int elsize) // жадный алгоритм
{
    char* elem1 = (char*)el1;
    char* elem2 = (char*)el2;

    unsigned long long temp = 0;
    // сколько temp вмещается в элемент через битовые операции
    int nTemps = elsize / sizeof(temp);

    // цикл {за одну операцию меняем не 1 байт, а 8}
    for (int i = 0; i < nTemps; i++)
    {
        memcpy(&temp, elem1, sizeof(unsigned long long));
               memcpy(elem1, elem2, sizeof(unsigned long long));
                      memcpy(elem2, &temp, sizeof(unsigned long long));

        // temp = *(unsigned long long*)elem1;
        //        *(unsigned long long*)elem1 = *(unsigned long long*)elem2;
        //                                      *(unsigned long long*)elem2 = temp;
        
        elem1 += 8;
        elem2 += 8;   
    } 

    if (elsize) //побитовая маска
    {
        
    }
    memcpy(&temp, elem1, sizeof(int));
    elem1 += 4;
    elem2 += 4;   


    
    //осталось 7 байт -> через битовую маску понять сколько байт осталась поменять
    // поменять оставшиеся байты

}

// void BitSwap (void* el1, void* el2) //побитовый
// {
//     void el;
//     el = *el1;
//          *el1 = *el2;
//                 *el2 = el;
// }

void Sort (void* arr, int nel, int elem_size, int (*Comparator)(const void*, const void*))
{
    for (int pass = 0; pass < nel - 1; pass++)
    {
        for (int i = 0; i < nel - pass - 1; i++)
        {
            void* el1 = (char*)arr +  i      * elem_size;
            void* el2 = (char*)arr + (i + 1) * elem_size;

            if (Comparator(el1, el2) > 0)
            {
                Swap (el1, el2);
            }
        }
    }
    // return arr;
}


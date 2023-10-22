#include <stdio.h>

void IntCompare(el1, el2, sizeof()) // swap for all types: передать указатели на элементы и их размер типа
{
    if (el1>el2)
    {
        int temp = (char*)el1 + i * sizeof()
    }
}



void BubbleSort(int arr[], int size)
{
    for (int pass = 0; pass < size; pass++)
    {
        int nswops = 0;
        for (int i = 0; i < size - 1 - pass; i++)
        {
            if (IntCompare(&arr[i], &arr[i+1])) (char*)arr + i * sizeof(int)
            {
                nswops++;

                // swap for all types, 

                int temp = arr[i];
                           arr[i] = arr[i + 1];
                                    arr[i + 1] = temp;
            }
        }
        if (nswops == 0) break;
    }
}

int main(int argc, char* argv[])
{
    printf("Введите количество чисел, которые необходимо отсортировать:");
    int size;
    scanf("%d", &size);

    printf("Введите числа, которые необходимо отсортировать:");
    int data[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    BubbleSort(data, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
}
#include "stdio.h"
#include "stdlib.h"

int min(int first, int sec)
{
    if (sec > first)
    {
        return first;
    }
    else
    {
        return sec;
    }
}

int jumpSearch(int arr[], int size, int key)
{

    int nextstep = size / 2;
    int step = size / 2;

    int previous = 0;

    while (arr[min(nextstep, size) - 1] < key)
    {
        previous = nextstep;

        // printf("Nextstep %d\n", nextstep);

        if (arr[nextstep] == key)
        {
            printf("same with key\n");
            return nextstep;
        }

        nextstep += step;

        if (previous >= size)
        {
            return -1;
        }
    }

    for (int j = previous; j < nextstep; j++)
    {
        if (arr[j] == key)
        {
            return j;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 29, 176, 282, 1093, 2019};
    int size = sizeof(arr) / sizeof(arr[0]);
    int toFind = 282;
    int indexNumber = jumpSearch(arr, size, toFind);

    if (indexNumber == -1)
    {
        printf("we didnt found %d", toFind);
    }
    else
    {
        printf("we found index at %d of your number : %d ", indexNumber, toFind);
    }

    return 0;
}

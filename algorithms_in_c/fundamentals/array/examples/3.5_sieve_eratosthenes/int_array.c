#include <stdio.h>

#define N 10000

// function declaration
void printArray(int len,int a[]);

int main()
{
    int i, j, a[N];

    for (i = 2; i < N; i++)
    {
        a[i] = 1;
    }
    printArray(N,a);

    for (i = 2; i < N; i++)
    {
        if (a[i])
        {
            for (j = i; i * j < N; j++)
            {
                a[i * j] = 0;
            }
        }
    }
    printArray(N,a);

    for (i = 2; i < N; i++)
    {
        if (a[i])
        {
            printf("%4d", i);
        }
    }
    printf("\n");

    printf("Size of arr: %d bytes", sizeof(a));

    return 0;
}

// function definition
void printArray(int len,int a[])
{
    printf("Array: \n\t");

    for (int i = 0; i < len; i++)
    {   
        printf("%2d ", i);
    }

    printf("\n\t");

    for (int i = 0; i < len; i++)
    {   
        printf("%2d ", a[i]);
    }
    printf("\n");
    return;
}


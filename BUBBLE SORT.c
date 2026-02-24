#include <stdio.h>
#include <stdlib.h>

int count = 0;

void bubbleSort(int A[], int n)
{
    int i, j, temp;

    for (i = 0; i <= n - 2; i++)
    {
        for (j = 0; j <= n - 2 - i; j++)
        {
            count = count + 1;   // counting comparisons

            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i, A[100];

    printf("\nEnter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
     }

    bubbleSort(A, n);

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
     printf("\nTotal number of comparisons: %d\n", count);

    return 0;
}

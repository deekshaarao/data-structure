#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge(int A[], int l, int m, int r)
{
    int i, j, k;
    int B[100];

    i = l;
    j = m + 1;
    k = l;

    while (i <= m && j <= r)
    {
        count = count + 1;

        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= m)
        B[k++] = A[i++];

    while (j <= r)
        B[k++] = A[j++];

    for (i = l; i <= r; i++)
        A[i] = B[i];
}

void mergesort(int A[], int l, int r)
{
    int m;

    if (l < r)
    {
        m = (l + r) / 2;

        mergesort(A, l, m);
        mergesort(A, m + 1, r);

        merge(A, l, m, r);
    }
}

int main()
{
    int A[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    mergesort(A, 0, n - 1);

    printf("Sorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nTotal number of comparisons: %d\n", count);

    return 0;
}

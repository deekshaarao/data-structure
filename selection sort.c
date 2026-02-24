#include <stdio.h>
#include <stdlib.h>

int count = 0;

void selectionSort(int A[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            count++;
            if (A[j] < A[min]) {
                min = j;
            }
        }


        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

int main() {
    int n, i, A[100];

    printf("\nEnter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    selectionSort(A, n);

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\nTotal number of comparisons: %d\n", count);

    return 0;
}

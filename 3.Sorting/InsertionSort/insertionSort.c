#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void insertionSort(int arr[], int n)
{
    count = 0;
    for (int i = 1; i < n; i++)
    {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && ++count && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}

void tester()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void plotter()
{
    srand(time(NULL));
    int *arr;
    int n;
    FILE *f1, *f2, *f3;
    f1 = fopen("best.txt", "w");
    f2 = fopen("avg.txt", "w");
    f3 = fopen("worst.txt", "w");
    n = 10;
    while (n <= 30000)
    {
        arr = (int *)malloc(n * sizeof(int));

        // best case
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1; // Sorted array
        }
        insertionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n; // random array
        }
        insertionSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // worst case
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i; // descending array
        }
        insertionSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);

        if (n < 10000)
        {
            n *= 10;
        }
        else
        {
            n += 10000;
        }
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1- Tester\n2- Plotter\n0- Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        default:
            return 0;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void selectionSort(int arr[], int n)
{
    count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[pos] > arr[j])
            { // find smallest element through j
                pos = j;
            }
        }
        if (pos != i)
        {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
        }
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
    selectionSort(arr, n);
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
    FILE *f1;
    f1 = fopen("plot.txt", "w");
    n = 10;
    while (n <= 30000)
    {
        arr = (int *)malloc(n * sizeof(int));

        // general case
        for (int i = 0; i < n; i++)
        {
            arr[i] = i; // for any array, the count will be same
        }
        selectionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

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
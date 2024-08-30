#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void bubbleSort(int arr[], int n)
{
    count = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
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
    bubbleSort(arr, n);
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
        bubbleSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n; // random array
        }
        bubbleSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // worst case
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i; // descending array
        }
        bubbleSort(arr, n);
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
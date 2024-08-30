#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high + 1;

    do
    {
        do
        {
            count++;
            i++;
        } while (arr[i] < pivot);

        do
        {
            count++;
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
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
    quickSort(arr, 0, n - 1);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void plotter()
{
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3;
    f1 = fopen("best.txt", "w");
    f2 = fopen("avg.txt", "w");
    f3 = fopen("worst.txt", "w");
    n = 4;

    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));
        // best case
        for (int i = 0; i < n; i++)
        {
            arr[i] = 1; // all elements are same
        }
        count = 0;
        quickSort(arr, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count);

        // average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n; // random array
        }
        count = 0;
        quickSort(arr, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count);

        // best case
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1; // sorted array
        }
        count = 0;
        quickSort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count);
        n = n * 2;
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
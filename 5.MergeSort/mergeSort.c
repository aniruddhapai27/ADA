#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void simpleMerge(int arr[], int low, int mid, int high)
{
    int i, j, k;

    int n1 = (mid - low) + 1;
    int n2 = (high - mid);
    int left[n1];
    int right[n2];

    for (i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    i = 0, j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        count++;
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    simpleMerge(arr, low, mid, high);
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
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void worst(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    int i, j;
    int n1 = (mid - low) + 1;
    int n2 = (high - mid);

    int even[n1], odd[n2];

    for (i = 0; i < n1; i++)
    {
        even[i] = arr[2 * i];
    }
    for (i = 0; i < n2; i++)
    {
        odd[i] = arr[2 * i + 1];
    }

    worst(even, low, mid);
    worst(odd, mid + 1, high);

    for (i = 0; i < n1; i++)
    {
        arr[i] = even[i];
    }
    for (j = 0; j < n2; j++)
    {
        arr[j + i] = odd[j];
    }
}

void plotter()
{
    srand(time(NULL));
    int *arr, n;
    FILE *f1, *f2, *f3, *worstArr;
    f1 = fopen("best.txt", "w");
    f2 = fopen("avg.txt", "w");
    f3 = fopen("worst.txt", "w");
    worstArr = fopen("wrstArr.txt", "w");

    for (n = 2; n <= 1024; n *= 2)
    {
        arr = (int *)malloc(n * sizeof(int));

        // Best case
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        count = 0;
        mergeSort(arr, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count);

        // worst case
        count = 0;
        worst(arr, 0, n - 1); // it takes the sorted array and makes worst case array
        for (int i = 0; i < n; i++)
        {
            fprintf(worstArr, "%d ", arr[i]);
        }
        fprintf(worstArr, "\n");
        mergeSort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        count = 0;
        mergeSort(arr, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count);
    }
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
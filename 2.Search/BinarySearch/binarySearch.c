#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    count++;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
    return binarySearch(arr, low, high, key);
}

void tester()
{
    int n, key;
    printf("Enter n: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter key: ");
    scanf("%d", &key);

    int idx = binarySearch(arr, 0, n - 1, key);
    if (idx == -1)
    {
        printf("Key not found\n");
    }
    else
    {
        printf("Key found at index: %d\n", idx);
    }
}

void plotter()
{
    srand(time(NULL));
    int *arr;
    int n, key;
    FILE *f1, *f2, *f3;
    f1 = fopen("best.txt", "w");
    f2 = fopen("avg.txt", "w");
    f3 = fopen("worst.txt", "w");
    n = 2;
    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));

        // best case
        for (int i = 0; i < n; i++)
        {
            arr[i] = 1;
        }
        key = 1;
        count = 0;
        binarySearch(arr, 0, n - 1, key);
        fprintf(f1, "%d\t%d\n", n, count);

        // average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        key = rand() % n;
        count = 0;
        binarySearch(arr, 0, n, key);
        fprintf(f2, "%d\t%d\n", n, count);

        // worst case
        for (int i = 0; i < n; i++)
        {
            arr[i] = 1;
        }
        key = 0;
        count = 0;
        binarySearch(arr, 0, n - 1, key);
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
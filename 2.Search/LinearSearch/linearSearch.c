// Linear search / Sequential search
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

int linearSearch(int arr[], int n, int key)
{
    count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
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

    int idx = linearSearch(arr, n, key);
    if (idx == -1)
    {
        printf("\nKey not found\n");
    }
    else
    {
        printf("\nKey found at index: %d\n", idx);
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
        linearSearch(arr, n, key);
        fprintf(f1, "%d\t%d\n", n, count);

        // average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        key = rand() % n;
        linearSearch(arr, n, key);
        fprintf(f2, "%d\t%d\n", n, count);

        // worst case
        for (int i = 0; i < n; i++)
        {
            arr[i] = 1;
        }
        key = 0;
        linearSearch(arr, n, key);
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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count1 = 0, count2;

void heapify(int arr[], int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;

    if (left < n && ++count1 && arr[left] > arr[maxIdx])
    {
        maxIdx = left;
    }
    if (right < n && ++count1 && arr[right] > arr[maxIdx])
    {
        maxIdx = right;
    }

    if (maxIdx != i)
    {
        int temp = arr[maxIdx];
        arr[maxIdx] = arr[i];
        arr[i] = temp;

        heapify(arr, maxIdx, n);
    }
}

void heapSort(int arr[], int n)
{
    // Step 1- Build maxHeap
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    count2 = count1; // The count for building maxHeap is stored in count2 variable
    count1 = 0;
    // Step 2- Push largest at the last
    for (int i = n - 1; i >= 0; i--)
    {
        // Swap first with last (Remove largest-first element)
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, 0, i);
    }
}

void tester()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);

    printf("\nSorted elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void plotter()
{
    srand(time(NULL));

    FILE *f1, *f2, *f3;
    f1 = fopen("best.txt", "w");
    f2 = fopen("avg.txt", "w");
    f3 = fopen("worst.txt", "w");

    int n = 100;

    while (n <= 1000)
    {
        int arr[n];

        // best case
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i + 1;
        }
        count1 = 0;
        heapSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count1 > count2 ? count1 : count2);

        // average case
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        count1 = 0;
        heapSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count1 > count2 ? count1 : count2);

        // worst case
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        count1 = 0;
        heapSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count1 > count2 ? count1 : count2);

        n += 100;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    int ch;
    while (1)
    {
        printf("Enter\n1- Tester\n2- Plotter\n0- Exit\n");
        scanf("%d", &ch);
        switch (ch)
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
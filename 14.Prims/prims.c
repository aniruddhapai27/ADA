#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int heapCount = 0, graphCount = 0, n;

typedef struct pair
{
    int node;
    int val;
    int parent;
} *Pair;

Pair createPair(int node, int val, int parent)
{
    Pair p = (Pair)malloc(sizeof(struct pair));
    p->node = node;
    p->val = val;
    p->parent = parent;
    return p;
}

typedef struct heap
{
    Pair *arr;
    int size;
} *Heap;

Heap createHeap(int edges)
{
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->arr = (Pair *)malloc(edges * sizeof(struct pair));
    h->size = 0;
    return h;
}

void add(Heap heap, Pair p)
{
    // Construct min heap
    heap->arr[heap->size] = p; // insert new pair at last of the array
    heap->size += 1;           // increase the heap size

    int x = heap->size - 1;   // last element index
    int parIdx = (x - 1) / 2; // parent of last element
    while (x > 0 && heap->arr[x]->val < heap->arr[parIdx]->val)
    {
        // check whether parent is greater then child, if yes, then swap
        Pair temp = heap->arr[x];
        heap->arr[x] = heap->arr[parIdx];
        heap->arr[parIdx] = temp;

        x = parIdx;
        parIdx = (x - 1) / 2;
    }
}

void heapify(Heap heap, int i)
{
    // for min heap
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int minIdx = i;
    heapCount++;

    // if parent val is greater than child val, swap
    if (left < heap->size && heap->arr[minIdx]->val > heap->arr[left]->val)
    {
        minIdx = left;
    }
    if (right < heap->size && heap->arr[minIdx]->val > heap->arr[right]->val)
    {
        minIdx = right;
    }

    if (minIdx != i)
    {
        Pair temp = heap->arr[minIdx];
        heap->arr[minIdx] = heap->arr[i];
        heap->arr[i] = temp;

        heapify(heap, minIdx);
    }
}

Pair delete(Heap heap)
{
    Pair p = heap->arr[0]; // store first pair in p

    // swap the first pair with last pair
    Pair temp = p;
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->arr[heap->size - 1] = temp;

    heap->size -= 1; // decrement heap size

    heapify(heap, 0);
    return p;
}

void prims(int graph[n][n], int n)
{
    int vis[n];
    int finalCost = 0;
    int mst[n][3];
    int idx = 0;

    // fill visited array with 0
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    int edges = 0;
    // count number of edges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] != INT_MAX)
            {
                edges++;
            }
        }
    }
    // create a heap of size equal to number of edges
    Heap heap = createHeap(edges);

    add(heap, createPair(0, 0, -1)); // add the first pair having node 0 and cost as 0 and its parent as -1

    while (heap->size != 0)
    {
        Pair cur = delete (heap);

        if (!vis[cur->node])
        {
            vis[cur->node] = 1;
            mst[idx][0] = cur->parent;
            mst[idx][1] = cur->node;
            mst[idx++][2] = cur->val;
            finalCost += cur->val;

            graphCount++;

            // put all the neighbouring vertex pairs in the heap
            for (int i = 0; i < n; i++)
            {
                if (cur->node != i && graph[cur->node][i] != INT_MAX)
                {
                    graphCount++;
                    add(heap, createPair(i, graph[cur->node][i], cur->node));
                }
            }
        }
    }

    printf("MST edges are: \n");
    for (int i = 1; i < n; i++)
    {
        printf("%d ---> %d = %d\n", mst[i][0], mst[i][1], mst[i][2]);
    }

    printf("Final cost is: %d\n", finalCost);
}

void tester()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter adjacency matrix (Enter cost if edge is present, else -1): \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == -1)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }

    prims(graph, n);
}

int main()
{
    FILE *f;
    f = fopen("prims.txt", "a");
    int choice;
    while (1)
    {
        printf("\n1- Tester\n0- Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tester();
            fprintf(f, "%d\t%d\n", n, graphCount > heapCount ? graphCount : heapCount);
            break;
        default:
            fclose(f);
            return 0;
        }
    }
}

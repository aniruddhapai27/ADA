#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int heapCount = 0;
int graphCount = 0;
int n;

typedef struct pair
{
    int node;
    int val;
} *Pair;

Pair createPair(int node, int val)
{
    Pair p = (Pair)malloc(sizeof(struct pair));
    p->node = node;
    p->val = val;
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
    heap->arr[heap->size] = p;
    heap->size += 1;

    int x = heap->size - 1;
    int parIdx = (x - 1) / 2;

    while (x > 0 && heap->arr[x]->val < heap->arr[parIdx]->val)
    {
        Pair temp = heap->arr[x];
        heap->arr[x] = heap->arr[parIdx];
        heap->arr[parIdx] = temp;

        x = parIdx;
        parIdx = (x - 1) / 2;
    }
    printf("Added to heap\n");
}

void heapify(Heap heap, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int minIdx = i;
    heapCount++;
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
        Pair temp = heap->arr[i];
        heap->arr[i] = heap->arr[minIdx];
        heap->arr[minIdx] = temp;

        heapify(heap, minIdx);
    }
}

Pair delete(Heap heap)
{
    Pair p = heap->arr[0];

    Pair temp = p;
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->arr[heap->size - 1] = temp;

    heap->size -= 1;
    heapify(heap, 0);
    return p;
}

void dijkstras(int graph[n][n], int source, int dist[n])
{
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }

    dist[source] = 0;
    int edges = 0;
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

    Heap heap = createHeap(edges);
    add(heap, createPair(source, 0));

    while (heap->size != 0)
    {
        Pair cur = delete (heap);
        if (!vis[cur->node])
        {
            vis[cur->node] = 1;
            graphCount++;

            for (int i = 0; i < n; i++)
            {
                if (cur->node != i && graph[cur->node][i] != INT_MAX)
                {
                    graphCount++;
                    int u = cur->node;
                    int v = i;
                    int wt = graph[u][v];

                    if (dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                        add(heap, createPair(v, dist[v]));
                    }
                }
            }
        }
    }
}

void tester()
{
    graphCount = 0;
    heapCount = 0;

    int source;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int graph[n][n], dist[n];
    printf("Enter adjacency matrix (Enter cost if present, else -1): \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source: ");
    scanf("%d", &source);

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

    dijkstras(graph, source, dist);

    printf("\nShortest distance for all node from %d is: \n", source);
    for (int i = 0; i < n; i++)
    {
        if (i != source)
        {
            printf("%d ---> %d = %d\n", source, i, dist[i]);
        }
    }
}

int main()
{
    FILE *f;
    f = fopen("dijkstras.txt", "a");
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
            return 0;
        }
    }
}
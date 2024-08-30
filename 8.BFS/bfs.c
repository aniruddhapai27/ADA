#include <stdio.h>
#include <stdlib.h>

int isCycle = 0, components = 0;
int count;
int n;
int isTester = 0;

void bfs(int graph[n][n], int vis[n], int node)
{
    int queue[n];
    int parent[n];
    int rear = -1, front = -1;
    vis[node] = 1;
    queue[++rear] = node;
    parent[rear] = -1;
    while (rear != front)
    {
        int cur = queue[++front];
        int par = parent[front];
        if (isTester)
        {
            printf("%d ", cur);
        }
        for (int i = 0; i < n; i++)
        {
            count++;
            if (i != par && graph[cur][i] == 1 && vis[i] == 1)
            {
                isCycle = 1;
            }
            if (graph[cur][i] == 1 && vis[i] == 0)
            {
                queue[++rear] = i;
                parent[rear] = cur;
                vis[i] = 1;
            }
        }
    }
}

void checkConnectivity(int graph[n][n])
{
    int vis[n];
    components = 0;
    count = 0;

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            components++;
            if (isTester)
            {
                printf("\nComponent %d: ", components);
            }
            bfs(graph, vis, i);
        }
    }
}

void tester()
{
    isTester = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];

    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    checkConnectivity(graph);

    printf("\nThe number of connected components: %d\n", components);

    if (isCycle)
    {
        printf("The graph is cyclic\n");
    }
    else
    {
        printf("The graph is acyclic\n");
    }
}

void plotter()
{
    isTester = 0;
    FILE *f1;
    f1 = fopen("bfs.txt", "w");
    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int graph[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    graph[i][j] = 1;
                }
                else
                {
                    graph[i][j] = 0;
                }
            }
        }
        checkConnectivity(graph);
        fprintf(f1, "%d\t%d\n", n, count);
    }
    fclose(f1);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1-Tester\n2-Plotter\n0-Exit\n");
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
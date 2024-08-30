#include <stdio.h>
#include <stdlib.h>

int count;
int n;
int top;
int isCycle;
int stack[100];
int path[100];

void dfs(int graph[n][n], int vis[n], int path[n], int start, int stack[n])
{
    vis[start] = 1;
    path[start] = 1;

    for (int i = 0; i < n; i++)
    {
        count++;
        if (path[i] == 1 && graph[start][i] == 1 && vis[i] == 1)
        {
            isCycle = 1;
            return;
        }
        if (graph[start][i] == 1 && vis[i] == 0)
        {
            dfs(graph, vis, path, i, stack);
        }
    }
    path[start] = 0;
    stack[++top] = start;
}

void checkConnectivity(int graph[n][n])
{
    int vis[n];
    isCycle = 0;
    count = 0;
    top = -1;

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(graph, vis, path, i, stack);
            if (isCycle)
            {
                return;
            }
        }
    }
}

void tester()
{
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
    if (isCycle)
    {
        printf("Cycle found, topological sort is not possible\n");
        return;
    }
    printf("Topological sorting is: \n");
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
}

void plotter()
{
    FILE *f1;
    f1 = fopen("topo.txt", "w");
    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int graph[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                graph[i][j] = 1;
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
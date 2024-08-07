#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct Graph
{
    int vertices;
    int edges;
    int *visit;
    struct node **adjLists;
};

typedef struct node *Node;

Node createnode(int n)
{
    Node nn = (Node)malloc(sizeof(struct node));
    nn->info = n;
    nn->next = NULL;
    return nn;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjLists = (struct node **)malloc(vertices * sizeof(struct node *));
    graph->visit = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visit[i] = 0;
    }
    return graph;
}

int count = 0, iscyclic = 0;

void DFS(struct Graph *graph, int vertex, int parent)
{
    // struct node* adjList = graph->adjLists[vertex];
    struct node *temp = graph->adjLists[vertex];

    count++;
    graph->visit[vertex] = 1;
    printf("-->%c ", vertex + 65);

    while (temp != NULL)
    {
        int connectedVertex = temp->info;
        if (graph->visit[connectedVertex] == 1 && connectedVertex != parent)
        {
            iscyclic = 1;
        }
        if (graph->visit[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex, vertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("ENTER THE NUMBER OF VERTICES\n");
    scanf("%d", &n);
    struct Graph *g = createGraph(n);

    printf("Enter the adjacency LIST \n");
    for (int i = 0; i < g->vertices; i++)
    {
        printf("Enter 1 for the vertices adjacent to vertex %c\n", i + 65);
        for (int j = 0; j < g->vertices; j++)
        {
            int key;
            printf("Is vertex %c adjacent to vertex %c (1 for yes, 0 for no): ", i + 65, j + 65);
            scanf("%d", &key);
            if (key == 1)
            {
                Node nn = createnode(j);
                nn->next = g->adjLists[i];
                g->adjLists[i] = nn;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < g->vertices; i++)
    {
        Node temp = g->adjLists[i];
        printf("THE VERTEX ADJACENT TO %c : ", i + 65);
        while (temp != NULL)
        {
            printf("%c ", temp->info + 65);
            temp = temp->next;
        }
        printf("\n");
    }

    int dfscount = 0;
    printf("\nDFS TRAVERSAL STARTING FROM NODE %c\n", 65);
    DFS(g, 0, -1);
    dfscount++;
    if (count == g->vertices)
    {
        printf("\nTHE GRAPH IS CONNECTED\n");
    }
    else
    {
        printf("\nTHE GRAPH IS NOT CONNECTED\n");
        int start = 1;
        while (count != g->vertices)
        {
            if (g->visit[start] != 1)
            {
                printf("\n");
                DFS(g, start, -1);
                dfscount++;
            }
            start++;
        }
    }

    if (iscyclic == 1)
    {
        printf("\nTHE GRAPH HAS A CYCLE\n");
    }
    else
    {
        printf("\nTHE GRAPH DOESN'T HAVE A CYCLE\n");
    }

    return 0;
}

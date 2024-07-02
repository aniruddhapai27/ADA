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
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visit = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visit[i] = 0;
    }

    return graph;
}

int count = 0, iscyclic = 0, gcount = 0;

void DFS(struct Graph *graph, int vertex, int parent)
{
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    count++;
    graph->visit[vertex] = 1;
    printf("-->%c ", vertex + 65);

    while (temp != NULL)
    {
        gcount++;
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
    gcount++;
}

void ploter(int k)
{
    FILE *fp1 = fopen("bestcase.txt", "a");
    FILE *fp2 = fopen("worstcase.txt", "a");

    for (int i = 1; i <= 10; i++)
    {
        int n = i;
        struct Graph *g = createGraph(n);
        Node temp;

        if (k == 0)
        {
            for (int i = 0; i < g->vertices - 1; i++)
            {
                Node nn = createnode(i + 1);
                nn->next = g->adjLists[i];
                g->adjLists[i] = nn;
            }
        }
        else if (k == 1)
        {
            for (int i = 0; i < g->vertices; i++)
            {
                for (int j = 0; j < g->vertices; j++)
                {
                    if (i != g->vertices - j - 1)
                    {
                        Node nn = createnode(g->vertices - j - 1);
                        nn->next = g->adjLists[i];
                        g->adjLists[i] = nn;
                    }
                }
            }
        }

        printf("\n");
        for (int i = 0; i < g->vertices; i++)
        {
            temp = g->adjLists[i];
            printf("THE VERTEX ADJACENT TO %c : ", i + 65);
            while (temp != NULL)
            {
                printf("%c ", temp->info + 65);
                temp = temp->next;
            }
            printf("\n");
        }

        gcount = 0;
        iscyclic = 0;
        count = 0;
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
                }
                start++;
            }
        }

        if (iscyclic)
        {
            printf("THE GRAPH HAS A CYCLE\n");
        }
        else
        {
            printf("THE GRAPH DOES NOT HAVE A CYCLE\n");
        }

        if (k == 0)
        {
            fprintf(fp1, "%d\t%d\n", n, gcount);
        }
        else
        {
            fprintf(fp2, "%d\t%d\n", n, gcount);
        }

        // Free memory for each graph instance
        for (int i = 0; i < g->vertices; i++)
        {
            Node current = g->adjLists[i];
            while (current != NULL)
            {
                Node temp = current;
                current = current->next;
                free(temp);
            }
        }
        free(g->adjLists);
        free(g->visit);
        free(g);
    }

    fclose(fp1);
    fclose(fp2);
}

int main()
{
    for (int i = 0; i < 2; i++)
    {
        ploter(i);
    }
    return 0;
}

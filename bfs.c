
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
enum
{
    BLACK,
    GREY,
    WHITE
};

typedef struct node
{
    int dest;
    struct node *next;
} node;

typedef struct graph
{
    node *adjl[MAX];
    int num; // nodes in graph
} graph;

graph *new_graph(int n)
{
    graph *g = malloc(sizeof(graph));
    g->num = n; // n=no.of nodes in the empty graph
    for (int i = 0; i < n; i++)
    {
        g->adjl[i] = NULL;
    }
    return g;
}

void addEdge(graph *g, int u, int v)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->dest = v;
    newNode->next = g->adjl[u];
    g->adjl[u] = newNode;

    newNode = (node *)malloc(sizeof(node));
    newNode->dest = u;
    newNode->next = g->adjl[v];
    g->adjl[v] = newNode;
}

void bfs(graph *g, int s)
{
    int color[MAX];
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < g->num; i++)
    {
        color[i] = BLACK;
    }
    queue[rear++] = s;
    color[s] = GREY;

    while (front < rear)
    {
        int u = queue[front++];
        color[u] = WHITE;
        printf("%d ", u);
        for (node *v = g->adjl[u]; v != NULL; v = v->next)
        {
            if (color[v->dest] == BLACK)
            {
                queue[rear++] = v->dest;
                color[v->dest] = GREY;
            }
        }
    }
}

int main()
{
    int n = 9;
    graph *g = new_graph(n);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 2, 3);
    addEdge(g, 1, 4);
    addEdge(g, 1, 5);
    addEdge(g, 4, 5);
    addEdge(g, 5, 6);
    addEdge(g, 5, 7);
    addEdge(g, 6, 7);

    printf("BFS starting from vertex 0: ");
    bfs(g, 0);
    printf("\n");

    return 0;
}
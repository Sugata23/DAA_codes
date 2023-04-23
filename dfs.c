#include <stdio.h>
#include <stdlib.h>
enum color{White, Gray, Black};

typedef struct list_node{
    int index_of_item;
    struct list_node *next;
}list_node;

typedef struct node {
    int data;
    enum color colr;
    list_node *head;
}node;

typedef struct graph{
    int number_of_vertices;
    node heads[];
}graph;

node* new_node(int data)
{   node *nd;
    nd= malloc(sizeof(node));
    nd->data = data;
    nd->head = NULL;
    nd->colr = White;
    return nd;
}

list_node* new_list_node(int item_index) {
    list_node *nd;
    nd = malloc(sizeof(list_node));
    nd->index_of_item = item_index;
    nd->next = NULL;
    return nd;
}


graph* new_graph(int number_of_vertices)
{   graph *g = malloc(sizeof(graph) + (number_of_vertices*sizeof(node)));
    g->number_of_vertices = number_of_vertices;
    int i;
        for(i=0; i<number_of_vertices; i++)
        {
            node *nd = new_node(-1);
            g->heads[i] = *nd;
        }
    return g;
}


void add_node_to_graph(graph *g, int data)
{   node *nd = new_node(data); 
    int i;
    for(i=0; i<g->number_of_vertices; i++)
    {
        if (g->heads[i].data < 0)
        {   g->heads[i] = *nd;
            break;
        }
  }
}


int in_graph_head_list(graph *g, int data)
{
    int i;
    for(i=0; i<g->number_of_vertices; i++)
    {   if(g->heads[i].data == data)
        return 1;
    }
    return 0;
}


void add_edge(graph *g, int source, int dest) {
 
    if(!in_graph_head_list(g, source))
	{
        add_node_to_graph(g, source);
    }
      
	if(!in_graph_head_list(g, dest))
	{
        add_node_to_graph(g, dest);
    }

    int i,j;

    for(i=0; i<g->number_of_vertices; i++)
	{
        if(g->heads[i].data == source)
		{	int dest_index;
        	for(j=0; j<g->number_of_vertices; j++)
			{
        		if(g->heads[j].data == dest)
				{	dest_index = j;
          			break;
        		}
        	}

        list_node *n = new_list_node(dest_index);
        if (g->heads[i].head == NULL)
		{	g->heads[i].head = n;
        }
        else
		{	list_node *temp;
        	temp = g->heads[i].head;
			while(temp->next != NULL)
			{	temp = temp->next;
        	}
        	temp->next = n;
        }
        break;
    }
  }
}



void dfs_visit(graph *g, node *i)
{
    i->colr = Gray;
	list_node *temp;
    temp = i->head;
    while(temp != NULL) {
        if (g->heads[temp->index_of_item].colr == White)
		{
          dfs_visit(g, &g->heads[temp->index_of_item]);
        }
        temp = temp->next;
    }
    i->colr = Black;
    printf("%d ",i->data);
}

void dfs(graph *g) {
    int i;
    for(i=0; i<g->number_of_vertices; i++)
	{	g->heads[i].colr = White;
    }
	for(i=0; i<g->number_of_vertices; i++)
	{	if (g->heads[i].colr == White) {
        	dfs_visit(g, &g->heads[i]);
    	}
  	}
}

int main()
{
    graph *g = new_graph(4);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 1, 4);
    add_edge(g, 4, 3);
	
	printf("DFS of the graph: ");
  	dfs(g);
  	printf("\n");
  	return 0;
}

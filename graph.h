#include<stdio.h>
#include<stdlib.h>
struct adjNode
{
    int ver;
    struct adjNode* next;
};
struct Graph
{
    int V;
    int* visited;
    struct adjNode** AdjList;
};
struct adjNode* createNode(int v)
{
    struct adjNode* newNode=(struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->ver=v;
    newNode->next=NULL;
    return newNode;
};
struct Graph* createGraph(int V)
{
    struct Graph* G=(struct Graph*)malloc(sizeof(struct Graph));
    G->V=V;
    G->visited=(int*)malloc(G->V*sizeof(int));
    G->AdjList=(struct node*)malloc(G->V*sizeof(struct node));
    int i;
    for(i=0;i<G->V;i++)
    {
        G->visited[i]=0;
    }
    for(i=0;i<G->V;i++)
    {
        G->AdjList[i]=NULL;
    }
    return G;
};
void addEdge(struct Graph* G,int src,int dest)
{
    struct node* newNode=createNode(dest);
    newNode->next=G->AdjList[src];
    G->AdjList[src]=newNode;

    newNode=createNode(src);
    newNode->next=G->AdjList[dest];
    G->AdjList[dest]=newNode;
}
void printGraph(struct Graph* graph)
{
    int i;
    for(i=0;i<graph->V;i++)
    {
        struct adjNode* temp=graph->AdjList[i];
        while(temp)
        {
            printf("%d ",temp->ver);
            temp=temp->next;
        }
        printf("\n");
    }
}

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "queue.h"
#include "graph.h"
void DFS(struct Graph* graph,int vertex)
{
    struct stack* Stack=createStack(graph->V);
    push(Stack,vertex);
    while(!IsEmptyStack(Stack))
    {
        int data=pop(Stack);
        if(graph->visited[data]==0)
        {
            graph->visited[data]=1;
            printf("%d ",data);
            struct node* temp=graph->AdjList[data];
            while(temp)
            {
                push(Stack,temp->ver);
                temp=temp->next;
            }
        }
    }
}
void BFS(struct Graph* graph,int vertex)
{
    struct queue* Queue=createQueue(graph->V);
    Enqueue(Queue,vertex);
    while(!IsEmptyQueue(Queue))
    {
        int data=Dequeue(Queue);
        if(graph->visited[data]==0)
        {
            graph->visited[data]=1;
            printf("%d ",data);
            struct node* temp=graph->AdjList[data];
            while(temp)
            {
                Enqueue(Queue,temp->ver);
                temp=temp->next;
            }
        }
    }
}


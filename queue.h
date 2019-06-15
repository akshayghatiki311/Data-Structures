#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int fro;
    int rear;
    int capacity;
    int *arr;
};
struct queue* createQueue(int size)
{
    struct queue* Queue=(struct queue*)malloc(sizeof(struct queue));
    Queue->fro=Queue->rear=-1;
    Queue->capacity=size;
    Queue->arr=(int*)malloc(Queue->capacity*sizeof(int));
    return Queue;
};
int IsEmptyQueue(struct queue* Queue)
{
    return (Queue->fro==-1);
}
int IsFullQueue(struct queue* Queue)
{
    return ((Queue->rear+1)%Queue->capacity==Queue->fro);
}
void Enqueue(struct queue* Queue,int data)
{
    if(IsFullQueue(Queue))
    {
        return;
    }
    else
    {
        Queue->rear=(Queue->rear+1)%Queue->capacity;
        Queue->arr[Queue->rear]=data;
        if(Queue->fro==-1)
        {
            Queue->fro=Queue->rear;
        }
    }
}
int Dequeue(struct queue* Queue)
{
    int temp;
    if(IsEmptyQueue(Queue))
    {
        return;
    }
    else
    {
        temp=Queue->arr[Queue->fro];
        if(Queue->fro==Queue->rear)
        {
            Queue->fro==Queue->rear==-1;
        }
        else
        {
            Queue->fro=(Queue->fro+1)%Queue->capacity;
        }
    }
    return temp;
}
void deleteQueue(struct queue* Queue)
{
    if(Queue)
    {
        if(Queue->arr)
        {
            free(Queue->arr);
        }
        free(Queue);
    }
}
void printQueue(struct queue* Queue)
{
    int i;
    if(IsEmptyQueue(Queue))
    {
        printf("Queue is Empty");
    }
    else
    {
        for(i=Queue->fro;i<=Queue->rear;i++)
        {
            printf("%d\n",Dequeue(Queue));
        }
    }
}

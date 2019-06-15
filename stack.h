#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int siz;
    int *arra;
};
struct stack* createStack(int size)
{
    struct stack* new_stack=(struct stack*)malloc(sizeof(struct stack));
    new_stack->siz=size;
    new_stack->top=-1;;
    new_stack->arra=(int*)malloc((new_stack->siz)*sizeof(int));
    return new_stack;
};
int IsFullStack(struct stack* Stack)
{
    return (Stack->top==(Stack->siz-1));
}
int IsEmptyStack(struct stack* Stack)
{
    return (Stack->top==-1);
}
void push(struct stack* Stack,int data)
{
    if(IsFullStack(Stack))
    {
        return;
    }
    else{
        Stack->top++;
        Stack->arra[Stack->top]=data;
    }
}
int pop(struct stack* Stack)
{
    int temp;
    if(IsEmptyStack(Stack))
    {
        return;
    }
    else
    {
        temp=Stack->arra[Stack->top];
        Stack->top--;
    }
    return temp;
}
int peek(struct stack* Stack)
{
    if(!IsEmptyStack(Stack))
        return Stack->arra[Stack->top];
}
void printStack(struct stack* Stack)
{
    int i;
    if(!IsEmptyStack(Stack))
        for(i=0;i<Stack->siz;i++)
        {
            printf("%d\n",pop(Stack));
        }
}
void deleteStack(struct stack* Stack)
{
    if(Stack)
    {
        if(Stack->arra)
        {
            free(Stack->arra);
        }
        free(Stack);
    }
}

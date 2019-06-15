#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* newNode(int data)
{
    struct node* new_Node=(struct node*)malloc(sizeof(struct node));
    new_Node->data=data;
    new_Node->next=NULL;
    return new_Node;
};
void addNodeAtEnd(struct node** head,int data)
{
    struct node* temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct node* new_Node=newNode(data);
    temp->next=new_Node;
}
void addNodeAtBegin(struct node** head,int data)
{
    struct node* new_Node=newNode(data);
    new_Node->next=*head;
    *head=new_Node;
}
void addInMiddle(struct node** head,int key,int val)
{
    struct node* new_Node=newNode(val);
    struct node* temp=*head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    struct node* temp1;
    temp1=temp->next;
    temp->next=new_Node;
    new_Node->next=temp1;
}
void deleteFromBegin(struct node** head)
{
    struct node* temp=*head;
    *head=temp->next;
    free(temp);
}
void deleteFromEnd(struct node** head)
{
    struct node* temp=*head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    struct node* rmv=temp->next;
    temp->next=NULL;
    free(rmv);
}
void deleteAfterKey(struct node** head,int key)
{
    struct node* temp=*head;
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    struct node* rmv=temp->next;
    temp->next=temp->next->next;
    free(rmv);
}
void swapNodes(struct node** head,int N1,int N2)
{
    struct node *temp1,*temp2,*temp3,*temp4,*Node1,*Node2;
    temp1=*head;
    temp2=*head;
    while(temp1->next->data!=N1)
    {
        temp1=temp1->next;
    }
    while(temp2->next->data!=N2)
    {
        temp2=temp2->next;
    }
    Node1=temp1->next;
    temp3=temp1->next->next;
    Node2=temp2->next;
    temp4=temp2->next->next;
    temp1->next=Node2;
    Node2->next=temp3;
    temp2->next=Node1;
    Node1->next=temp4;
}
void reverseList(struct node** head)
{
    struct node *prev,*curr,*nxt;
    prev=NULL;
    nxt=NULL;
    curr=*head;
   // nxt=curr->next;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    *head=prev;
}
void printList(struct node* head)
{
    struct node* temp;
    temp=head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

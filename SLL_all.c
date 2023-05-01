#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* link;
};

struct node* create_node();
struct node* search_node(struct node* head);
struct node* ins_start(struct node* head);
struct node* ins_middle(struct node* head);
struct node* ins_end(struct node* head);
struct node* del_start(struct node* head);
struct node* del_middle(struct node* head);
struct node* del_end(struct node* head);

struct node* head=NULL;
struct node* pNew;
struct node* pNew2;
struct node* newNode;

struct node* create_node()
{
    int size,i=0;
    printf("Enter the size of node you want to create: ");
    scanf("%d",&size);

    while(i<size)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL)
        {
            printf("\nMemory Overflow");
        }else{

        if(head==NULL)
        {
            head=pNew=newNode;
            pNew->link = NULL;
        }else
        {
            pNew->link=newNode;
            pNew=newNode;
            pNew->link=NULL;

        }
        printf("\nEnte the data:  ");
        scanf("%d",&pNew->data);
        }
    }
}

struct node* search_node(struct node* head)
{
int element;
printf("Enter the element to be searched:  ");
scanf("%d",&element);

pNew=head;
while(pNew->link!=NULL)
{
    if(pNew->data==element)
    {
        printf("Element Found at %p location. ",pNew);
        break;
    }else
    {
        pNew->link=pNew;
    }
}
if(pNew->link==NULL)
{
    printf("Element not found");
}
}

struct node* ins_start(struct node* head)
{
    
    newNode=(struct node*)malloc(sizeof(struct node));
    pNew=newNode;

     printf("Enter data to be instered in the new node: ");
     scanf("%d",&pNew->data);

    pNew=head;
    pNew=newNode;
    pNew->link=head;
    head=pNew;


}

struct node* ins_end(struct node* head)
{
    
    newNode=(struct node*)malloc(sizeof(struct node));
    pNew=newNode;

    printf("Enter the data: ");
    scanf("%d",&pNew->data);
    
    pNew=head;
    while(pNew->link!=NULL)
    {
        pNew=pNew->link;
    }
    pNew->link=newNode;
    pNew=newNode;
    pNew->link=NULL;

}

struct node* ins_middle(struct node* head)
{
    int pos,i=0;
    

    newNode=(struct node*)malloc(sizeof(struct node));
    pNew=newNode;
    
    printf("Enter the data:  ");
    scanf("%d",&pNew->data);

    pNew=head;
    printf("Enter the position you want to enter the node in:  ");
    scanf("%d",&pos);

    while(i<pos-1)
    {
        pNew=pNew->link;
        i++;
    }
    newNode->link=pNew->link;
    pNew->link=newNode;

}

struct node* del_start(struct node* head)
{
    pNew=head;
    if(head==NULL)
    {
        printf("Empty linked list!");
    }else
    {

    head=pNew->link;

    free(pNew);
    }
}

struct node* del_end(struct node* head)
{
    pNew=head;
    while(pNew->link!=NULL)
    {
        pNew2=pNew;
        pNew=pNew->link;
    }   
    if(pNew==head)
    {
    head=NULL;
    free(pNew);
    }else
    {
    pNew2->link=NULL;
    free(pNew);
    }

}

struct node* del_middle(struct node* head)
{
    int pos,i=1;
    printf("Enter the position to delete: ");
    scanf("%d",&pos);

    pNew=head;
    while(i<pos-1)
    {
        pNew=pNew->link;
        i++;  
    }
    pNew2=pNew->link;
    pNew->link=pNew2->link;

    free(pNew2);

}

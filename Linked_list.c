#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
    {
        int data;
        struct node* link;
    };

bool searchNode(struct node *head,struct node **pPre,struct node **pLoc,int element)
{
    *pPre=NULL;
    *pLoc=head;

    while(*pLoc!=NULL && (element>(*pLoc)->data))
    {
        *pPre=*pLoc;
        *pLoc=(*pLoc)->link;

    }
    if(*pLoc==NULL)
    {
        return false;
    }else if((*pLoc)->data==element)
    {
        return true;
    }else
    {
        return false;
    }
   
}
int main()
{
 

struct node  *head=NULL; //creating the start/head of the linked list, its only a pointer.
struct node  *newNode; //defining a new node pointer which points to the new node.
struct node *pNew; //used to assign links to nodes.
struct node *pPre;
struct node *pLoc;
int n,search_element;

printf("Enter the number of nodes to create: ");
scanf("%d",&n);
printf("Enter data in ascending order\n");

for(int i=1;i<=n;i++){
newNode = (struct node*)malloc(sizeof(struct node)); //allocating space for the new node and pointing it with new node pointer.
printf("Enter data for node %d: ",i);
scanf("%d",&newNode->data);

newNode->link=NULL; //after taking data, the link part of the node is assigned to null to signify the last node.

if(head==NULL)//reason being if you always point it to the new node the link between all the nodes will be destroyed 
{
    head=pNew=newNode;//so for start of the linked list head is assigned to new node aswell as the temp value for future linking.
    
}else
{
pNew->link=newNode;//pNew->link means the pNew is pointing to the node, to access the node's link we use head.
pNew = newNode;//Now the temp/pNew value points to newly created node.
}

}
pNew=head;
printf("Printing nodes \n");
for(int i=1;i<=n;i++)
{
    printf("%d\n",pNew->data);
    pNew=pNew->link;

}

printf("Enter the element to be searched: ");
scanf("%d",&search_element);

bool found = searchNode(head,&pPre,&pLoc,search_element);


    if(found)
    {
        printf("Found at pPre %p and pLoc %p",pPre,pLoc);
    }else
    {
        printf("Not found!");
    }
    
    return 0;

}


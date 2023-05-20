#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct node
{
    void* data;
    struct node* link;

};

struct stack
{
    int count;
    struct node* top;
};

struct stack* create_stack(void)//creates the stack counter and top pointer using malloc.
{
    struct stack* newStack;

    newStack=(struct stack*)malloc(sizeof(struct stack));

    if(newStack)
    {
        newStack->count=0;
        newStack->top=NULL;
    }
    return newStack;
}
bool pushStack(struct stack* newStack,void* data_ins)//pushes/creates a linked list stack.
{
    struct node* newNode;

    newNode=(struct node*)malloc(sizeof(struct node));

    if(!newNode)
    {
        return false;
    }else
    {
        newNode->data=data_ins;
        newNode->link=newStack->top;
        newStack->top=newNode;

        (newStack->count)++;
    }
}
void* popStack(struct stack* newStack)
{
    void* data_pop;

    struct node* pNew;
    if(newStack->top==NULL)
    {
        data_pop=NULL;
    }else
    {
        pNew=newStack->top;
        data_pop=newStack->top->data;
        newStack->top=newStack->top->link;
        free(pNew);
        (newStack->count)--;
    }
    return data_pop;
}
void* topStack(struct stack* newStack)
{
    if(newStack->count==0)
    {
        return NULL;
    }else
    {
        return newStack->top->data;
    }
}
int countStack(struct stack* newStack)
{
    return newStack->count;
}
bool fullStack(struct stack* newStack)
{
    struct node* pNew;
    if(pNew=(struct node*)malloc (sizeof(*(newStack->top))))
    {
        free(pNew);
        return false;
    }
    return true;
}
bool emptyStack(struct stack* newStack)
{
 if(newStack->count==0)
 {
    return true;
 }else
 {
    return false;
 }
}

struct stack* destory_stack(struct stack* newStack)
{
    if(newStack)
    {
        struct node* pNew;
        while(newStack->top!=NULL)
        {
            free(newStack->top->data);
            pNew = newStack->top;
            newStack->top=newStack->top->link;
            free(pNew);
        }
        free(newStack);
    }
    return NULL;

}

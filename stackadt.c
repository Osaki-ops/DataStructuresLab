#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    void* datap;
    struct node* next;
}stack_node;

typedef struct
{
    int count;
    stack_node* top;
}STACK;

STACK* create_stack()
{
    STACK*stack = (STACK*) malloc(sizeof(STACK));
    if(stack)
    {
        stack -> count = 0;
        stack -> top = NULL;
    }
    return stack;
}

void push(void* data, STACK* stack)
{
    stack_node* new = (stack_node*)malloc(sizeof(stack_node));
    if(new)
    {
        new->datap = data;
        new->next = stack -> top;
        stack -> top = new;
        (stack -> count)++;
    }
    else
    printf("NO memory, stack is full\n");
}

void* pop(STACK*stack)
{
    void* dp;
    if(stack -> top == NULL)
    {
        dp = NULL;
    }
    else
    {
        stack_node* temp = stack -> top;
        dp = (stack -> top)-> datap;
        stack -> top = (stack -> top)-> next;
        free(temp);
        (stack -> count)--;
    }
    return dp;

}

void* top(STACK*stack)
{
    void* dptr;
    if(stack -> count == 0){
        dptr = NULL;
    }
    else{
    dptr = (stack -> top) -> datap;
    }

    return dptr;
}

int count(STACK* stack)
{
    return stack->count;
}

STACK* destroy(STACK*stack)
{
    if(stack)
    {
        stack_node* temp;
        while(stack->top != NULL)
        {
            free(stack->top->datap);
            temp = stack->top;
            stack->top = stack->top->next;
            free(temp);

        }
        free(stack);
    }
    return NULL;
}

bool emptyStack (STACK* stack) 
{
    if(stack->count == 0)
    return true;
    else
    return false;
}

bool fullStack (STACK* stack) 
{
    stack_node* temp;
    if (temp = (stack_node*)malloc (sizeof(*(stack->top))))
    {
        free(temp);
        return false;
    }
    return true;
}

int main()
{
    int c,d;
    
    STACK* stack = create_stack();
    printf("******Stack ADT******\n");
    do{
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Print data at Top of stack\n");
        printf("4.Display no. of elements in stack\n");
        printf("5.Destroy stack\n");
        printf("6.Check stack is empty or not\n");
        printf("7.Check stack is full or not\n");
        printf("\nEnter choice:");
        scanf("%d",&c);
        int *t, *p;
        switch (c)
        {
        case 1:
            printf("Enter value:");
            scanf("%d",&d);
            void* data = malloc(sizeof(int));
            *(int*)data = d;
             push(data, stack);
            break;

        case 2:
            p = (int*)pop(stack);
            if(p!=NULL)
            printf("Element %d is poped out\n",*p);
            else
            printf("Stack is empty!\n");
            break;

        case 3:
            t = (int*)top(stack);
            if(t!=NULL)
            printf("Top element in stack:%d\n",*t);
            else
            printf("Stack is empty!\n");
            break;

        case 4:
            printf("No. of element in stack:%d\n",count(stack));
            break;

        case 5:
            destroy(stack);
            printf("Stack destroyed!\n");
            return 0;

        case 6:
            if(emptyStack(stack))
            printf("Stack is empty\n");
            else
            printf("Stack is not empty\n");
            break;

        case 7:
            if(fullStack(stack))
            printf("Stack is full\n");
            else
            printf("Stack is not full\n");
            break;

        default:
            printf("Invalid input");
            break;
        }
    }while(c!=0);
    
    return 0;
}


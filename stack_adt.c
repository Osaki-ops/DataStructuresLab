#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct stack {
    int count;
    struct node* top;
};

struct node {
    void* data;
    struct node* link;
};

struct student {
    char name[50];
    int rollNo;
    float midMarks;
};

struct stack* create_stack(struct stack* stack) {
    struct stack* newStack;
    newStack = (struct stack*)malloc(sizeof(struct stack));

    if (newStack) {
        newStack->count = 0;
        newStack->top = NULL;
    }
    return newStack;
}

bool pushStack(struct stack* newStack, void* data_ins) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    if (!newNode) {
        return false;
    } else {
        newNode->data = data_ins;
        newNode->link = newStack->top;
        newStack->top = newNode;
        newStack->count++;
    }
    return true;
}

void* popStack(struct stack* newStack) {
    void* data_pop;
    struct node* pNew;

    if (newStack->count == 0) {
        data_pop = NULL;
    } else {
        pNew = newStack->top;
        data_pop = newStack->top->data;
        newStack->top = newStack->top->link;
        free(pNew);
        newStack->count--;
    }
    return data_pop;
}

void* topStack(struct stack* newStack) {
    if (newStack->count == 0) {
        return NULL;
    } else {
        return newStack->top->data;
    }
}

int countStack(struct stack* newStack) {
    return newStack->count;
}

bool fullStack(struct stack* newStack) {
    struct node* pNew;
    if (pNew = (struct node*)malloc(sizeof(*(newStack->top)))) {
        free(pNew);
        return false;
    }
    return true;
}

bool emptyStack(struct stack* newStack) {
    return (newStack->top == NULL);
}

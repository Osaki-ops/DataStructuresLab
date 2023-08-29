#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node* link;
};

struct node* poly_insert(struct node* head,int coeff,int power)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;
    if(head==NULL)
    {
        head = newNode;
        temp = newNode;
    }else
    {
        temp->link = newNode;
        temp = newNode;
    }
    return head;
}

struct node* remove_dup(struct node* poly)
{
    struct node* temp1;
    struct node* temp2;
    struct node* dup;

    temp1 = poly;
    while(temp1!=NULL && temp1->link!=NULL)
    {
        temp2 = temp1;
        while(temp2->link!=NULL)
        {
            if(temp1->power==temp2->link->power)
            {
                temp1->coeff = temp1->coeff + temp2->coeff;
                dup = temp2->link;
                temp2->link = temp2->link->link;
                free(dup);
            }else
            {
                temp2 = temp2->link;
            }
        }
        temp1=temp1->link;
    }
    return poly;
}

struct node* poly_multiply(struct node* poly1, struct node* poly2)
{
    struct node* result = NULL;
    struct node* temp1 = poly1;

    while (temp1 != NULL)
    {
        struct node* temp2 = poly2;
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int power = temp1->power + temp2->power;
            result = poly_insert(result, coeff, power);
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }

    result = remove_dup(result);
    return result;
}

void disp_poly(struct node* poly)
{
    struct node* temp = poly;
    int count = 1;

    while(temp!=NULL)
    {
        if (temp->coeff != 0) 
        {
            if (!count && temp->coeff > 0) 
            {
                printf(" + ");
            }
            if (temp->power == 0) 
            {
                printf("%d", temp->coeff);
            } else if (temp->power == 1) 
            {
                printf("%dx", temp->coeff);
            } else 
            {
                printf("%dx^%d", temp->coeff, temp->power);
            }
            count = 0;
        }
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;

    char choice;
    int coeff,power;

    while(1)
    {
        scanf("%d %d",&coeff,&power);
        poly1 = poly_insert(poly1,coeff,power);
        scanf(" %c",&choice);
        if(choice == 'y'||choice == 'Y')
        continue;
        if(choice == 'n'||choice == 'N')
        break;
    }
    while(1)
    {
        scanf("%d %d",&coeff,&power);
        poly2 = poly_insert(poly2,coeff,power);
        scanf(" %c",&choice);
        if(choice == 'y'|| choice == 'Y')
        continue;
        if(choice == 'n'||choice == 'N')
        break;
    }
    result = poly_multiply(poly1,poly2);

    disp_poly(result);
    return 0;
}


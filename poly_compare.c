#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int power;
    struct node* link;
};

struct node* poly_insert(struct node* newNode,int coeff,int power)
{
    struct node* temp;

    if(newNode==NULL)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        temp = newNode;
        temp->coeff = coeff;
        temp->power = power;
        temp->link = NULL;
    }else
    {
        temp=newNode;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = (struct node*)malloc(sizeof(struct node));
        temp= temp->link;
        temp->coeff = coeff;
        temp->power = power;
        temp->link = NULL;
    }
    return newNode;
}

void poly_compare(struct node* poly1,struct node* poly2)
{
    while(poly1 !=NULL && poly2!=NULL)
    {
        if(poly1->coeff!= poly2->coeff || poly1->power!=poly2->power)
        {
            break;
        }
        poly1=poly1->link;
        poly2=poly2->link;
    }
    if(poly1==NULL && poly2==NULL)
    {
        printf("Polynomials are Equal.");
    }else
    {
    printf("Polynomials are Not Equal.");
    }
}
void disp_poly(struct node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        if (poly->coeff != 0) {
            printf("(%dx^%d)", poly->coeff, poly->power);
            if (poly->link != NULL) 
            {
                printf(" + ");
            }
        }
        poly = poly->link;
    }
    printf("\n");
}

int main()
{
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    int count,count2,coeff,pow;
    scanf("%d",&count);
    for(int i = 0;i<count;i++)
    {
        scanf("%d %d",&coeff, &pow);
        poly1=poly_insert(poly1,coeff,pow);
    }
    scanf("%d",&count2);
    for(int i = 0;i<count2;i++)
    {
        scanf("%d %d",&coeff, &pow);
        poly2=poly_insert(poly2,coeff,pow);
    }
    disp_poly(poly1);
    disp_poly(poly2);
    poly_compare(poly1,poly2);
}

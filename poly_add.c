#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int power;
    struct node* link;
};

struct node* poly_insert(struct node* head, int coeff, int power) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;

    if (head == NULL || power < head->power) {
        newNode->link = head;
        head = newNode;
        return head;
    }

    struct node* temp = head;
    while (temp->link != NULL && temp->link->power <= power) {
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}

void disp_poly(struct node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        if (poly->coeff != 0) {
            printf("%dx^%d", poly->coeff, poly->power);
            if (poly->link != NULL) 
            {
                printf(" + ");
            }
        }
        poly = poly->link;
    }
    printf("\n");
}

struct node* sum(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node* temp = NULL; 

    while (poly1 || poly2) {
        int res_coeff = 0;
        int res_power = 0;
        if (poly1 && poly2) {
            if (poly1->power == poly2->power) {
                res_coeff = poly1->coeff + poly2->coeff;
                res_power = poly1->power;
                poly1 = poly1->link;
                poly2 = poly2->link;
            } else if (poly1->power > poly2->power) {
                res_coeff = poly1->coeff;
                res_power = poly1->power;
                poly1 = poly1->link;
            } else {
                res_coeff = poly2->coeff;
                res_power = poly2->power;
                poly2 = poly2->link;
            }
        } else if (poly1) {
            res_coeff = poly1->coeff;
            res_power = poly1->power;
            poly1 = poly1->link;
        } else {
            res_coeff = poly2->coeff;
            res_power = poly2->power;
            poly2 = poly2->link;
        }

        if (res_coeff != 0) {
            if (temp == NULL) {
                result = poly_insert(result, res_coeff, res_power);
                temp = result;
            } else {
                temp->link = (struct node*)malloc(sizeof(struct node));
                temp = temp->link;
                temp->coeff = res_coeff;
                temp->power = res_power;
                temp->link = NULL;
            }
        }
    }
    return result;
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    int coeff, pow;
    while(1)
    {
        scanf("%d %d",&coeff,&pow);
        if(coeff==0 && pow ==0)
        {
            break;
        }
        poly1 = poly_insert(poly1,coeff,pow);
    }
    while(1)
    {
        scanf("%d %d",&coeff,&pow);
        if(coeff==0 && pow==0)
        {
            break;
        }
        poly2 = poly_insert(poly2,coeff,pow);
    }
    struct node* result = sum(poly1, poly2);
    disp_poly(poly1);
    disp_poly(poly2);
    disp_poly(result);

    return 0;
}

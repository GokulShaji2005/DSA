#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *link;
};

struct node *Pptr = NULL, *Qptr = NULL, *Rptr = NULL;

// Function to create a new node
struct node* create_node(int coeff, int exp) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->link = NULL;
    return new_node;
}

// Function to insert node at the end of the list
void insert_end(struct node** head, int coeff, int exp) {
    struct node* new_node = create_node(coeff, exp);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* temp = *head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new_node;
    }
}

// Function to print polynomial
void print_poly(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        if(temp->coeff > 0 && temp != head) printf("+");
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->link;
    }
    printf("\n");
}

// Function to add two polynomials and return the result
struct node* add_poly(struct node* P, struct node* Q) {
    struct node* R = NULL;
    while (P != NULL && Q != NULL) {
        if (P->exp == Q->exp) {
            int sum_coeff = P->coeff + Q->coeff;
            if (sum_coeff != 0) {
                insert_end(&R, sum_coeff, P->exp);
            }
            P = P->link;
            Q = Q->link;
        } else if (P->exp > Q->exp) {
            insert_end(&R, P->coeff, P->exp);
            P = P->link;
        } else { // Q->exp > P->exp
            insert_end(&R, Q->coeff, Q->exp);
            Q = Q->link;
        }
    }

    // Add remaining nodes if any
    while (P != NULL) {
        insert_end(&R, P->coeff, P->exp);
        P = P->link;
    }
    while (Q != NULL) {
        insert_end(&R, Q->coeff, Q->exp);
        Q = Q->link;
    }
    return R;
}

int main() {
    int t1, t2, coeff, exp;
    printf("First polynomial\n");
    printf("Enter t1 terms:");
    scanf("%d", &t1);


    for (int i = 0; i < t1; i++) {
   printf("Enter the %d coefficient:",i+1);
        scanf("%d", &coeff);
        printf("Enter the %d exponent:",i+1);
        scanf("%d", &exp);
        insert_end(&Pptr, coeff, exp);
    }
printf("Second Polynomial");
printf("\n");
    printf("Enter t2 terms ");
    scanf("%d", &t2);

   
    for (int j = 0; j < t2; j++) {
        printf("Enter the %d coefficient:",j+1);
        scanf("%d", &coeff);
          printf("Enter the %d exponent:",j+1);
        scanf("%d", &exp);
        insert_end(&Qptr, coeff, exp);
    }

    printf("First Polynomial: ");
    print_poly(Pptr);

    printf("Second Polynomial: ");
    print_poly(Qptr);

    // Add the two polynomials
    Rptr = add_poly(Pptr, Qptr);

    printf("Resultant Polynomial: ");
    print_poly(Rptr);

    return 0;
}


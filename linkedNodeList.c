#include <stdio.h>
#include <stdlib.h>

/* 
    Author: Hayden Stewart
    Filename: lab6.c
*/

/* struct for a node in the linked list */
struct node {
    int num;
    struct node *next;
} *stnode;

/* Function to create the linked list
 * Parameter: int n, number of nodes */
void createNodeList(int n);

/* Reverses the order of the list */
void reverseDispList();   

/* Function to display the linked list */
void displayList();

/* Main Function (DO NOT EDIT) */
int main() {
    int n;

    // Displaying the purpose of the program
    printf("\n\n Linked List : Create a singly linked list and print it in reverse order :\n");
    printf("------------------------------------------------------------------------------\n");

    // Inputting the number of nodes for the linked list
    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    // Creating the linked list with n nodes
    createNodeList(n);
    printf("\n Data entered in the list are : \n");		

    // Displaying the data entered in the linked list
    displayList();

    // Reversing the linked list
    reverseDispList();
    printf("\n The list in reverse are :  \n");

    // Displaying the reversed linked list
    displayList();

    return 0;
}

/* Function to create the linked list
 * Parameter: int n, number of nodes */
void createNodeList(int n) {
    int i = 1;

    if (n <= 0) {
        printf(" Node list length must be at least 1.");
        return;
    }
        
    stnode = (struct node*)malloc(sizeof(struct node));
    struct node *tmp;

    printf(" Input data for node %d : ", i);
    scanf("%d", &stnode->num);
    tmp = stnode;

    if (n == 1) return;

    for (i = 2; i <= n; i++) {
        
        tmp->next = (struct node*)malloc(sizeof(struct node));

        tmp = tmp->next;
 
        printf(" Input data for node %d : ", i);
        scanf("%d", &tmp->num);
    }

}

/* Function to reverse the linked list */
// Push nums to stack, then pop off stack to print in reverse
// Assumes max list size of 999
void reverseDispList() {

    struct node *tmp = stnode;
    struct node *reverse;
    int stack[999], i = 0;

    while (tmp != NULL) {
        stack[i++] = tmp->num;
        tmp = tmp->next;
    }

    if (i > 0) {  
        reverse = (struct node*)malloc(sizeof(struct node));
        reverse->num = stack[--i];
        tmp = reverse;

        while (i > 0) {
            tmp->next = (struct node*)malloc(sizeof(struct node));
            tmp = tmp->next;
            tmp->num = stack[--i];
        }
    }
    stnode = reverse;
}

/* Function to display the linked list */
void displayList() {
    struct node *tmp;
    if(stnode == NULL) {
        printf(" No data found in the list.");
    } else {
        tmp = stnode;
        while(tmp != NULL) {
            printf(" Data = %d\n", tmp->num);
            tmp = tmp->next;
        }
    }
}
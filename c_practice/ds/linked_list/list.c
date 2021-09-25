#include <stdio.h>


typedef struct node {
    int *next;
    int data;
} node;

typedef struct linked_list {
    node* head;
    node* curr;
} linked_list;


int main(void)
{
    printf("Lists!\n");

    return 0;
}
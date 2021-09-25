#include <stdio.h>


typedef struct node {
    char *next;
    char data;
} node;

typedef struct linked_list {
    node* head;
    node* curr;
} linked_list;


int main(void)
{
    char *text = "Lists!\n";

    printf("%c", *text);
    printf("%s", text);

    linked_list list;
    

    return 0;
}
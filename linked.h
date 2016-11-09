#include <stdlib.h>
#include <stdio.h>

typedef struct {
    NODE *next_ptr;
    int id;
    char name
} NODE;

static NODE *head_ptr = NULL;

void main_interface(int ch) {
    switch(ch) {
        case 'a':
            list_node_add();
            break;
        case 'd':
            if (!list_node_delete()) {
                list_node_print();
            }
            break;
        case 'p': 
            list_node_print();
            break;
        default:
            break;
    }
}

NODE *list_node_create(void) {
    NODE *ptr;
    if ((ptr=(NODE *)malloc(sizeof(NODE))) == NULL) {
        ErrorExit("malloc() failed.\n")
    }
    ptr->next_ptr = NULL;
    ptr->id = 0;
    return ptr;
}

void list_node_add(void) {
    NODE *new_ptr, *ptr;
    new_ptr = list_node_create();
    printf("Enter the student name and ID: ")
    scanf("%s%ld", new_ptr->name, &new_ptr->id)
}
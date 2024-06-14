// name: Xinchen Xu
// email: xu.xinc@northeastern.edu
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    struct node *head;
} List;

/*-----creating the nodes----------*/
node_t* newNode(int num) {
    node_t *n = (node_t *)malloc(sizeof(node_t));
    n->data = num;
    n->next = NULL;
    return n;
}

/*---creating linked list----*/
List* init_LL() {
    List *l = (List *)malloc(sizeof(List));
    l->head = NULL;
    return l;
}

/*---Insert the nodes at the beginning of the list---*/
void insertFirst(List *l, int data) {
    node_t *n = newNode(data);
    n->next = l->head;
    l->head = n;
}

/*----display the output--------*/
void display(List *l) {
    node_t *temp;
    temp = l->head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*-------reversing the linked list using recursion------*/
void reverseUtil(node_t *curr, node_t *prev, List *l) {
    if (!curr->next) {
        l->head = curr;
        curr->next = prev;
        return;
    }

    node_t *next = curr->next;
    curr->next = prev;
    reverseUtil(next, curr, l);
}

void reverse(List *l, node_t *ptr) {
    if (!l->head) {
        return;
    }
    reverseUtil(ptr, NULL, l);
}

/*----Free the nodes-----*/
void freenode(List *l) {
    node_t *temp;
    while (l->head) {
        temp = l->head->next;
        free(l->head);
        l->head = temp;
    }
}

/*-----Main program--------------*/
int main() {
    List *list = init_LL();

    insertFirst(list, 44);
    insertFirst(list, 33);
    insertFirst(list, 22);
    insertFirst(list, 11);
    display(list);
    reverse(list, list->head);
    display(list);

    freenode(list);
    free(list);
    return 0;
}


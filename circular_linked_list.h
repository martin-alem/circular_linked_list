//
// Created by Martin Alemajoh on 9/24/2020.
//

#ifndef CIRCULAR_LINKED_LIST_CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_CIRCULAR_LINKED_LIST_H

/*
 * structure to represent a node in a linked list
*/
typedef struct node{
    const void *data;
    struct node *next;
}Node;


/*
 * structure to represent a linked list
*/
typedef struct clinkedlist {
    Node *head;
    Node *tail;
}CLinkedList;


/*
 * DEF: Initialize CLinkedList
 * PARAM1: CLinkedList *list - circular linkedlist structure to be initialize
 * RETURN: returns void
*/
void initList(CLinkedList *list);

/*
 * DEF: Frees a node allocated with malloc
 * PARAM1: void **node - address of pointer to node
 * RETURN: returns void
*/
void freeNode(void **node);


/*
 * DEF: Clears a list and frees all allocated node
 * PARAM1: CLinkedList *list - circular linkedlist structure to be cleared
 * RETURN: returns void
*/
void clearList(CLinkedList *list);

/*
 * DEF: inserts data to the list
 * PARAM1: CLinkedList *list - circular linkedlist structure.
 * PARAM2: const void *type - data to be stored in list
 * RETURN: pointer to node otherwise NULL
*/
Node *addList(CLinkedList *list, const void *data);


/*
 * DEF: removes data from front of the list
 * PARAM1: CLinkedList *list - circular linkedlist structure
 * RETURN: returns void
*/
void removeFront(CLinkedList *list);

/*
 * DEF: returns a pointer to Node
 * PARAM1: CLinkedList *list - circular linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns a pointer to Node;
*/
Node *getNode(CLinkedList *list, int index);

/*
 * DEF: gets the number of elements in a list
 * PARAM1: CLinkedList *list - circular linkedlist structure
 * RETURN: returns number of elements
*/
unsigned int getSize(CLinkedList *list);


/*
 * DEF: returns a pointer to the data at a particular index
 * PARAM1: SLinkedList *list - single linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns a pointer to data;
*/
void *get(CLinkedList *list, int index);


/*
 * DEF: removes the element next to the one whose index is provided
 * PARAM1: SLinkedList *list - single linkedlist structure
 * PARAM2: int index - index of data in list
 * RETURN: returns void
*/
void removeNext(CLinkedList *list, int index);



#endif //CIRCULAR_LINKED_LIST_CIRCULAR_LINKED_LIST_H

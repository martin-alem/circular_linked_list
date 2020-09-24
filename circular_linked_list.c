//
// Created by Martin Alemajoh on 9/24/2020.
//

#include "circular_linked_list.h"
#include <stdlib.h>


void initList(CLinkedList *list){
    list->head = NULL;
    list->tail = NULL;
}


void freeNode(void **node){

    if(node != NULL && *node != NULL){
        free(*node);
        *node = NULL;
    }
}

void clearList(CLinkedList *list){

    if(list->head != NULL) {

        Node *node = list->head->next, *nextNode, *tempNode = list->head;

        while(node != tempNode){
            nextNode = node->next;
            freeNode((void **)&node);
            node = nextNode;
        }
        freeNode((void **)&tempNode);
        list->head = NULL;
        list->tail = NULL;
    }
}

Node *addList(CLinkedList *list, const void *data){

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;

    if(list->head == NULL){
        list->head = node;
    }
    else{
        list->tail->next = node;
        node->next = list->head;
    }
    list->tail = node;
    return node;
}


void *get(CLinkedList *list, int index){

    if(list->head != NULL){

        if(index >= getSize(list) || index <= -1){
            return NULL;
        }
        Node *node = list->head;
        void *n;
        unsigned int i = 0;

        do {
            n = (void *)node->data;
            node = node->next;
            i += 1;
        }while (i <= index);

        return n;
    }
    return NULL;
}

void removeFront(CLinkedList *list){

    if(list->head != NULL) {

        if(list->head == list->tail){
            freeNode((void **)&list->head);
            list->head = NULL;
            list->tail = NULL;
        }
        else {
            Node *node = list->head;
            Node *nextNode = node->next;
            freeNode((void **) &node);
            list->head = nextNode;
            list->tail->next = list->head;
        }
    }
}


void removeNext(CLinkedList *list, int index){

    if(list->head != NULL){

        if(index >= getSize(list) || index < 0){
            return;
        }
        Node *node = getNode(list, index);
        if(node != NULL){
            Node *nextNextNode, *nextNode;

            if(node == list->tail){
                nextNextNode = node->next->next;
                nextNode = node->next;
                list->head = nextNextNode;
                list->tail->next = list->head;
                freeNode((void **)&nextNode);
            }
            else{
                nextNextNode = node->next->next;
                nextNode = node->next;
                node->next = nextNextNode;
                freeNode((void **)&nextNode);
            }
        }
    }
}


Node *getNode(CLinkedList *list, int index){

    if(list->head != NULL) {

        Node *node = list->head;
        unsigned int i = 0;
        Node *n;
        do{
            n = node;
            node = node->next;
            i += 1;
        }while(i <= index);
        return n;
    }
    return NULL;
}


unsigned int getSize(CLinkedList *list){

    unsigned int len = 0;
    if(list->head != NULL){
        Node *tempNode = list->head, *node = list->head, *nextNode;
        do{
            nextNode = node->next;
            node = nextNode;
            len += 1;
        }while(node != tempNode);
    }
    return len;
}




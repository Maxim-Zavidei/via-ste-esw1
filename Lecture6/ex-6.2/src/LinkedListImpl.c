#include <stdlib.h>
#include "LinkedList.h"

typedef struct ListNode {
    void* item;
    ListNode_t* next;
} ListNode;

typedef struct LinkedList {
    uint16_t size;
    ListNode_t* head;
} LinkedList;

LinkedList_t LinkedList_create() {
    LinkedList_t new_linkedlist = calloc(sizeof(LinkedList), 1);

    if (NULL == new_linkedlist) return NULL;

    new_linkedlist->size = 0;
    new_linkedlist->head = NULL;

    return new_linkedlist;
}

enum LinkedListReturnCode destroy(LinkedList_t self) {

    if (NULL == self) return NOT_FOUND;

    ListNode_t tmp = NULL;
    while (self->head != NULL) {
        tmp = self->head;
        self->head = tmp->next;
        free(tmp);
    }

    // Free the list structure itself
    free(self);
    return OK;
}

enum LinkedListReturnCode push(LinkedList_t self, void* item) {
    if (NULL == self) return NOT_FOUND;
    ListNode_t new_node = calloc(sizeof(ListNode), 1);
    new_node->item = item;
    new_node->next = self->head;
    self->head = new_node;
    self->size++;
    return OK;
}

void* pull(LinkedList_t self) {
    ListNode_t temp = self->head;
    return temp->item;
}

enum LinkedListReturnCode containsItem(LinkedList_t self, void* item) {
    if (NULL == self) return NOT_FOUND;

    ListNode_t currentNode = self->head;
    while (currentNode != NULL) {
        ListNode_t nextNode = currentNode->next;
        if (currentNode->item == item) return FOUND;
        currentNode = nextNode;
    }
    return NOT_FOUND;
}

enum LinkedListReturnCode removeItem(LinkedList_t self, void* item) {
    if (NULL == self) return NOT_FOUND;

    ListNode_t currentNode = self->head;
    ListNode_t previousNode = NULL;
    while (currentNode != NULL) {
        if (currentNode->item == item) {
            // If the item is at the beggining of the list
            if (previousNode == NULL) {
                self->head = NULL;
                free(currentNode);
                self->size--;
                return OK;
            } else {
                // If the item is at the end of the list
                if (currentNode->next == NULL) {
                    free(currentNode);
                    previousNode->next = NULL;
                } else {
                    // If the item is in the middle of the list
                    previousNode->next = currentNode->next;
                    free(currentNode);
                }
                self->size--;
                return OK;
            }
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    return NOT_FOUND;
}

void* peekItemByIndex(LinkedList_t self, uint16_t index) {
    if (NULL == self) return NOT_FOUND;

    ListNode_t currentNode = self->head;
    for (int i = 1; i < index; i++) {
        if (currentNode == NULL) return NOT_FOUND;
        currentNode = currentNode->next;
    }

    return currentNode->item;
}

uint16_t length(LinkedList_t self) {
    if (NULL == self) return 0;
    return self->size;
}

void clear(LinkedList_t self) {
    if (NULL == self) return NOT_FOUND;

    // Free all the nodes
    ListNode_t currentNode = self->head;
    while (currentNode != NULL) {
        ListNode_t nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    self->head = NULL;
}

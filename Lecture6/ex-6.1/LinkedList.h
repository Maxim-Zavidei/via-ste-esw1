#pragma once

#include <stdint.h>

enum LinkedListReturnCode {
    OK,
    EMPTY,
    NOT_FOUND,
    FULL,
    FOUND
};

typedef struct ListNode* ListNode_t;
typedef struct LinkedList* LinkedList_t;

LinkedList_t create();
enum LinkedListReturnCode destroy(LinkedList_t self);
enum LinkedListReturnCode push(LinkedList_t self, void* item);
void* pull(LinkedList_t self);
enum LinkedListReturnCode containsItem(LinkedList_t self, void* item);
enum LinkedListReturnCode removeItem(LinkedList_t self, void* item);
void* peekItemByIndex(LinkedList_t self, uint16_t index);
uint16_t length(LinkedList_t self);
void clear(LinkedList_t self);

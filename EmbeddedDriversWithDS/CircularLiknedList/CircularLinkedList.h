#ifndef __CIRCULARLINKEDLIST_H__
#define __CIRCULARLINKEDLIST_H__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>



typedef struct TaskNode
{
    uint8_t TaskNum;
    uint8_t Priority;
    char TaskName[20];
    struct TaskNode* next;
} TaskNode_t;

typedef struct CircularLinkedList
{
    TaskNode_t *Head;
    TaskNode_t *Tail;
} CircularLinkedList_t;

CircularLinkedList_t* CLL_Init(void);

int CLL_InsertTaskPriority(CircularLinkedList_t* clist, uint8_t id, uint8_t priority, const char* name);

TaskNode_t* CLL_GetHighestPriorityTask(CircularLinkedList_t* clist);

int CLL_PopHighestPriorityTask(CircularLinkedList_t* clist);

#endif
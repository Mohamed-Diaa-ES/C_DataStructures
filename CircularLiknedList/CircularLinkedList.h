#ifndef __CIRCULARLINKEDLIST__
#define __CIRCULARLINKEDLIST__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    uint8_t TaskPriority;
    char TaskName[10];
    uint8_t Task;

}TaskInfo;
typedef struct Node
{
    uint8_t info;
    struct Node* next;

}Node_t;

typedef struct CircularLinkedList
{
    Node_t *Start;
}CircularLinkedList_t;

Node_t* CreateElement ();
uint8_t AddTask(CircularLinkedList_t*cllist)
#endif
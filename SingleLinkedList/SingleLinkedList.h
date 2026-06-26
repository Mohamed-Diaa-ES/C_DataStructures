#ifndef __SINGLLINKEDLIST__
#define __SINGLELINKEDLIST__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node
{
    uint8_t info;
    struct Node* next;

}Node_t;

typedef struct SingleLinkedList
{
    Node_t *Start;
}SingleLinkedList_t;

Node_t* CreateElement ();
void DisplayList(SingleLinkedList_t* llist);

uint32_t CountNode(SingleLinkedList_t*llist);
int  search (SingleLinkedList_t*llist,uint8_t SearchVal);

int InsertAtBeginning(SingleLinkedList_t*llist,uint8_t val);

int InsertAtEnd(SingleLinkedList_t*llist,uint8_t val);

int InsertAfterNode(SingleLinkedList_t*llist,int AfterVal);

int InsertBeforeNode(SingleLinkedList_t*llist,int BeforeVal);
#endif
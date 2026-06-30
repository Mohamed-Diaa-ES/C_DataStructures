#include "CircularLinkedList.h"

Node_t *CreateElement()
{
    Node_t *NewElement = (Node_t *)malloc(sizeof(Node_t));
    /* other ways to do it:
     1- using static var
    static Node_t *NewELement=  NULL;
    NewElement =(Node_t*)malloc(sizeof(Node_t));

    or to return it directly
    return ((Node_t*)malloc(sizeof(Node_t)));

    */
    return NewElement;
}

void DisplayList(CircularLinkedList_t* llist);

uint32_t CountNode(CircularLinkedList_t*llist);
int  search (CircularLinkedList_t*llist,uint8_t SearchVal);

int InsertAtBeginning(CircularLinkedList_t*llist,uint8_t val);

int InsertAtEnd(CircularLinkedList_t*llist,uint8_t val);

int InsertAfterNode(CircularLinkedList_t*llist,int AfterVal);

int InsertBeforeNode(CircularLinkedList_t*llist,int BeforeVal);
#include "CircularLinkedList.h"

CircularLinkedList_t *CLL_Init(void)
{
    CircularLinkedList_t *clist = (CircularLinkedList_t *)malloc(sizeof(CircularLinkedList_t));
    if (clist != NULL)
    {
        clist->Head = NULL;
        clist->Tail = NULL;
    }
    return clist;
}

int CLL_InsertTaskPriority(CircularLinkedList_t *clist, uint8_t id, uint8_t priority, const char *name)
{
    if (clist == NULL)
    {
        return -1;
    }

    TaskNode_t *newNode = (TaskNode_t *)malloc(sizeof(TaskNode_t));
    if (newNode == NULL)
        return -1;

    newNode->TaskNum = id;
    newNode->Priority = priority;

    uint8_t i = 0;
    while (name[i] != '\0' && i <15)
    {
        newNode->TaskName[i] = name[i];
        i++;
    }
    newNode->TaskName[i] = '\0';

    if (clist->Head == NULL)
    {
        clist->Head = newNode;
        clist->Tail = newNode;
        newNode->next = clist->Head;
    }
    else if (priority < clist->Head->Priority)
    {
        newNode->next = clist->Head;
        clist->Head = newNode;
        clist->Tail->next = clist->Head;
    }
    else
    {
        TaskNode_t *current = clist->Head;

        while (current->next != clist->Head && current->next->Priority <= priority)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (current == clist->Tail)
        {
            clist->Tail = newNode;
        }
    }

    return 1;
}

TaskNode_t *CLL_GetHighestPriorityTask(CircularLinkedList_t *clist)
{
    if (clist == NULL || clist->Head == NULL)
        return NULL;
    return clist->Head; 
}

int CLL_PopHighestPriorityTask(CircularLinkedList_t *clist)
{
    if (clist == NULL || clist->Head == NULL)
        return -1;

    TaskNode_t *temp = clist->Head;

    if (clist->Head == clist->Tail)
    {
        clist->Head = NULL;
        clist->Tail = NULL;
    }
    else
    {
        clist->Head = clist->Head->next;
        clist->Tail->next = clist->Head;
    }

    free(temp);
    return 1;
}
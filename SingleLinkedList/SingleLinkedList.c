#include "SingleLinkedList.h"

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
void DisplayList(SingleLinkedList_t *llist)
{
    if (llist != NULL)
    {
        Node_t *goer = llist->Start;
        uint8_t i = 0;
        while (goer != NULL)
        {
            printf("Element Number %d = %d", i, goer->info);
            goer = goer->next;
            i++;
        }
    }
    else
    {
        printf("List is empty!");
    }
}

uint32_t CountNode(SingleLinkedList_t *llist)
{
    if (llist != NULL)
    {
        Node_t *goer = llist->Start;
        uint32_t count = 0;
        while (goer != NULL)
        {
            goer = goer->next;
            count++;
        }
        return count;
    }
    else
    {
        printf("List is empty!");
        return 0;
    }
}
int search(SingleLinkedList_t *llist, uint8_t SearchVal)
{
    if (llist != NULL)
    {
        Node_t *goer = llist->Start;
        uint8_t pos = 0;
        while (goer != NULL && goer->info != SearchVal)
        {
            goer = goer->next;
            pos++;
        }
        if (goer != NULL)
        {
            return pos;
        }

        return -1;
    }
    else
    {
        printf("List is empty!");
        return -1;
    }
}

int InsertAtBeginning(SingleLinkedList_t *llist, uint8_t val)
{
    Node_t *u;
    if (llist == NULL)
    {
        llist = (SingleLinkedList_t *)malloc(sizeof(SingleLinkedList_t));
        u = CreateElement();
        // checking if u is safe  and malloc found a place to hold data;
        if (llist != NULL && u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = val;
            return 1;
        }
        else
        {
            if (u != NULL)
                free(u);
            printf("No memory availble to allocate the var right now");
            return -1;
        }
    }

    if (llist->Start == NULL)
    {
        u = CreateElement();
        if (u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = val;
            return 1;
        }
        else
        {
            if (u != NULL)
            free(u);
            
            printf("No memory availble to allocate the var right now");
            return -1;
        }
    }

    Node_t *TobeAdded = CreateElement();
    if (TobeAdded != NULL)
    {
        u = llist->Start;
        llist->Start= TobeAdded;
        TobeAdded->next= u;
        TobeAdded->info= val;
            return 1;

    }
    else
    {
        printf("No memory availble to allocate the var right now");
        return -1;
    }
}

int InsertAtEnd(SingleLinkedList_t *llist, uint8_t val)
{
       Node_t *u;
    if (llist == NULL)
    {
        llist = (SingleLinkedList_t *)malloc(sizeof(SingleLinkedList_t));
        u = CreateElement();
        // checking if u is safe  and malloc found a place to hold data;
        if (llist != NULL && u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = val;
            return 1;
        }
        else
        {
            if (u != NULL)
                free(u);
            printf("No memory availble to allocate the var right now");
            return -1;
        }
    }

    if (llist->Start == NULL)
    {
        u = CreateElement();
        if (u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = val;
            return 1;
        }
        else
        {

            printf("No memory availble to allocate the var right now");
                    return -1;

        }
    }

    Node_t *TobeAdded = CreateElement();
    while(u->next!= NULL) u=u->next;

    if (TobeAdded != NULL)
    {
        u ->next=TobeAdded ;
        TobeAdded->next= NULL;
        TobeAdded->info= val;
            return 1;

    }
    else
    {
        printf("No memory availble to allocate the var right now");
        return -1;
    }
}

int InsertAfterNode(SingleLinkedList_t *llist, int AfterVal)
{
           Node_t *u;
    if (llist == NULL)
    {
        llist = (SingleLinkedList_t *)malloc(sizeof(SingleLinkedList_t));
        u = CreateElement();
        // checking if u is safe  and malloc found a place to hold data;
        if (llist != NULL && u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = AfterVal;
            return 1;
        }
        else
        {
            if (u != NULL)
                free(u);
            printf("No memory availble to allocate the var right now");
            return -1;
        }
    }

    if (llist->Start == NULL)
    {
        u = CreateElement();
        if (u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = AfterVal;
            return 1;
        }
        else
        {

            printf("No memory availble to allocate the var right now\n");
                    return -1;

        }
    }

    Node_t *TobeAdded = CreateElement();
    while(u!= NULL)
    { 
        if(u->info==AfterVal)
        {
            break;
        }
        u=u->next;
    }
    if(u==NULL) 
    {   
        printf("The Value is not found\n");
        return -1;
    }
    if (TobeAdded != NULL)
    {

        TobeAdded->next= u ->next ;
        u->next= TobeAdded;
        TobeAdded->info= AfterVal;
            return 1;

    }
    else
    {
        printf("No memory availble to allocate the var right now");
        return -1;
    }

}

int InsertBeforeNode(SingleLinkedList_t *llist, int BeforeVal)
{
          Node_t *u;
    if (llist == NULL)
    {
        llist = (SingleLinkedList_t *)malloc(sizeof(SingleLinkedList_t));
        u = CreateElement();
        // checking if u is safe  and malloc found a place to hold data;
        if (llist != NULL && u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = BeforeVal;
            return 1;
        }
        else
        {
            if (u != NULL)
                free(u);
            printf("No memory availble to allocate the var right now");
            return -1;
        }
    }

    if (llist->Start == NULL)
    {
        u = CreateElement();
        if (u != NULL)
        {
            llist->Start = u;
            u->next = NULL;
            u->info = BeforeVal;
            return 1;
        }
        else
        {

            printf("No memory availble to allocate the var right now\n");
                    return -1;

        }
    }

    Node_t *TobeAdded = CreateElement();
    while(u->next!= NULL)
    { 
        if(u->next->info==BeforeVal)
        {
            break;
        }
        u=u->next;
    }
    if(u->next==NULL) 
    {   
        printf("The Value is not found\n");
        return -1;
    }
    if (TobeAdded != NULL)
    {

        TobeAdded->next= u ->next ;
        u->next= TobeAdded;
        TobeAdded->info= BeforeVal;
            return 1;

    }
    else
    {
        printf("No memory availble to allocate the var right now");
        return -1;
    }
}
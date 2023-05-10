#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "type.c"

List* newList() 
{
    List* list;
    list = (List*) malloc(sizeof(List));

    list->start = INVALID;
    list->available = 0;
    list->nodes[MAX - 1].next = INVALID;

    int i;

    for (i = 0; i < MAX - 1; i++)
        list->nodes[i].next = i + 1;
    
    return list;
}

int getAvailableNode(List* list) 
{
    int result = list->available;

    if (result != INVALID)
        list->available = list->nodes[list->available].next;

    return result;
}

int returnRemovedNode(List* list, int j) 
{
    list->nodes[j].next = list->available;
    list->available = j;
}

bool insertSorted(List* list, int value) 
{
    if (list->available == INVALID)
        return false;

    int i = list->start;
    int previous = INVALID;

    while (i != INVALID && list->nodes[i].value < value)    
    {
        previous = i;
        i = list->nodes[i].next;
    }

    if (i != INVALID && list->nodes[i].value == value)
        return false;

    i = getAvailableNode(list);
    list->nodes[i].value = value;

    if (previous == INVALID)
    {
        list->nodes[i].next = list->start;
        list->start = i;
    }
    else 
    {
        list->nodes[i].next = list->nodes[previous].next;
        list->nodes[previous].next = i;
    }

    return true;
}

bool removeElement(List* list, int value) 
{
    int i = list->start;
    int previous = INVALID;

    while (i != INVALID && list->nodes[i].value < value)    
    {
        previous = i;
        i = list->nodes[i].next;
    }

    if (i == INVALID || list->nodes[i].value != value)
        return false;

    if (previous == INVALID) 
        list->start = list->nodes[i].next;
    else    
        list->nodes[previous].next = list->nodes[i].next;

    returnRemovedNode(list, i);    

    return true;
}

bool addElements(List* list, int values[MAX], int length) 
{
    for (int i = 0; i < length - 1; i++)
        insertSorted(list, values[i]);
    
    return true;   
}

int length(List* list) 
{
    int i = list->start;
    int length = 0;

    while (i != INVALID) 
    {
        length++;
        i = list->nodes[i].next;
    }
    
    return length;
}

void showElements(List* list) 
{
    int i = list->start;

    if (i == INVALID) 
    {
        printf("The list is empty");
        return;
    }

    printf("Linked List: \n");
    while (i != INVALID) 
    {
        printf("%i \n", list->nodes[i].value);
        i = list->nodes[i].next;
    }
}

int sequencialSearch(List* list, int value) 
{
    int i = list->start;

    while (i != INVALID && list->nodes[i].value < value)
        i = list->nodes[i].next;

    if (i != INVALID && list->nodes[i].value == value)
        return i;
    else
        return INVALID;
}
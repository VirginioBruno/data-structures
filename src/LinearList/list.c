#include <stdio.h>
#include "type.c"
#include <stdbool.h>

LinearList newList() 
{
    LinearList list;
    list.length = 0;
    return list;
}

void addElements(LinearList* list, int elements[MAX], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        list->elements[i] = elements[i];
        list->length++;
    }
}

int length(LinearList* list) 
{
    return list->length;
}

void showElements(LinearList* list) 
{
    if (list->length <= 0) 
    {
        printf("The list is empty \n");
        return;
    }

    printf("List: \n\n");

    for (int i = 0; i < list->length; i++)
        printf("%i \n", list->elements[i]);

    printf("\n");
}

int linearSearch(LinearList* list, int value)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->elements[i] == value)
            return i;
    }

    return -1;
}

int sentinelLinearSearch(LinearList* list, int value)
{
    int i = 0;
    list->elements[list->length] = value;

    while (list->elements[i] != value) i++;
    
    if (i == list->length) return -1;
    else return i;
}

int binarySearch(LinearList* list, int value)
{
    int left = 0;
    int right = list->length - 1;
    int middle = 0;

    while (left <= right) 
    {
        middle = left + (right - left) / 2;
        int middleValue = list->elements[middle];

        if (middleValue == value) return middle;
        else if (middleValue < value) left = middle + 1;
        else right = middle - 1;
    }

    return -1;
}

bool insertAt(LinearList* list, int index, int value) 
{
    if (list->length == MAX) 
    {
        printf("The list is full \n");
        return false;
    }

    if (index < 0 || index > MAX || index > list->length)
    {
        printf("The index %i is invalid \n", index);
        return false;
    }

    for (int i = list->length; i > index; i--)
    {
        list->elements[i] = list->elements[i - 1];
    }

    list->elements[index] = value;
    list->length++;

    return true;
}

bool sortedInsert(LinearList* list, int value) 
{
    if (list->length == MAX) 
    {
        printf("The list is full \n");
        return false;
    }

    int i = list->length;

    while (i > 0 && list->elements[i - 1] > value)
    {
        list->elements[i] = list->elements[i - 1];
        i--;
    }

    list->elements[i] = value;
    list->length++;

    return true;
}

void addSortedElements(LinearList* list, int elements[MAX], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        sortedInsert(list, elements[i]);
    }
}

bool removeValue(LinearList* list, int value) 
{
    if (list->length == 0) 
    {
        printf("The list doesnt have any elements \n");
        return false;
    }

    int index = binarySearch(list, value);

    if (index < 0)
    {
        printf("The index %i is invalid \n", index);
        return false;
    }

    for (int i = index; i < list->length - 1; i++)
    {
        list->elements[i] = list->elements[i + 1];
    }

    list->length--;

    return true;
}
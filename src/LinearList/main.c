#include <stdio.h>
#include "list.c"

int main()
{
    int elements[] = { 12, 6, 4, 15, 10, 8 };
    int length = sizeof(elements) / sizeof(int);
    List* list = newSortedList(elements, length);

    printf("This list contains %i elements \n\n", list->length);

    showElements(list);

    removeValue(list, 12);

    showElements(list);

    int elementIndex = linearSearch(&list, 8);
    (elementIndex < 0) ? printf("Element not found \n") : printf("Element found at index %i \n", elementIndex);

    printf("This list contains %i elements \n\n", list->length);

    free(list);
    return 0;
}
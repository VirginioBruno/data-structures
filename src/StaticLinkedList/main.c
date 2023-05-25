#include <stdio.h>
#include "list.c"

int main()
{
    int elements[] = { 12, 6, 4, 15, 10, 8 };
    int length = sizeof(elements) / sizeof(elements[0]);
    List* list = newList();

    addElements(list, elements, length);

    printf("This list contains %i elements \n\n", getLength(list));

    showElements(list);

    removeElement(list, 12);

    showElements(list);

    int elementIndex = sequencialSearch(list, 8);
    (elementIndex < 0) ? printf("Element not found \n") : printf("Element found at index %i \n", elementIndex);

    printf("This list contains %i elements \n\n", getLength(list));

    free(list);
    return 0;
}
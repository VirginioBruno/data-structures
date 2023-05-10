#include "type.c"
#include <stdbool.h>

LinkedList* newList();
bool addElements(LinkedList* list, int values[], int length);
int length(LinkedList* list);
void showElements(LinkedList* list);
int sequencialSearch(LinkedList* list, int value);
bool insertSorted(LinkedList* list, int value);
bool removeElement(LinkedList* list, int value);
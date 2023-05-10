#include "type.c"
#include <stdbool.h>

LinearList newList();
int length(LinearList* list);
void showElements(LinearList* list);
void addElements(LinearList* list, int elements[MAX], int length);
void addSortedElements(LinearList* list, int elements[MAX], int length);
int linearSearch(LinearList* list, int value);
int sentinelLinearSearch(LinearList* list, int value);
int binarySearch(LinearList* list, int value);
bool insertAt(LinearList* list, int index, int value);
bool sortedInsert(LinearList* list, int value);
bool removeValue(LinearList* list, int value);
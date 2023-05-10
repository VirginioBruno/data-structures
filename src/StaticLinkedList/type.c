#include <stdio.h>

#define MAX 50
#define INVALID -1

typedef struct 
{
    int value;
    int next;
} Node;

typedef struct 
{
    Node nodes[MAX];
    int start;
    int available;
} List;
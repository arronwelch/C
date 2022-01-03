
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// typedef struct _node{
//     int value;
//     struct _node *next;
// } Node;

typedef struct _list{
    Node *head;
    // Node *tail;
} List;

void add(List *pList, int number);

int main(int argc, char const *argv[])
{
    // Node *head = NULL;

    List list;
    list.head = NULL;

    int number;
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list,number);
        }
    } while (number != -1);

    return 0;
}

void add(List *pList, int number)
{
    // 1.add to linked-list
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    // 2.find the last
    Node *last = pList->head;
    if (last != NULL)
    {
        while (last->next)
        {
            last = last->next;
        }
        // 3.attach
        last->next = p;
    }
    else
    {
        pList->head = p;
    }
}

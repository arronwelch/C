
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// typedef struct _node{
//     int value;
//     struct _node *next;
// } Node;

typedef struct _list
{
    Node *head;
    // Node *tail;
} List;

void add(List *pList, int number);
void print(List *list);

int main(int argc, char const *argv[])
{
    List list;
    list.head = NULL;

    int number;
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list, number);
        }
    } while (number != -1);

    print(&list);
    scanf("%d", &number);
    Node *p;
    int isFound = 0;
    for (p = list.head; p; p = p->next)
    {
        if (p->value == number)
        {
            printf("isFound\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound)
    {
        printf("isNoFound\n");
    }

    Node *q;
    for (q = NULL, p = list.head; p; q = p, p = p->next)
    {
        if (p->value == number)
        {
            if (q)
            {
                q->next = p->next;
            }
            else
            {
                list.head = p->next;
            }
            free(p);
            break;
        }
    }

    for (p = list.head; p; p = q)
    {
        q = p->next;
        free(p);
    }

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

void print(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%d\t", p->value);
    }
    printf("\n");
}

#include <stdio.h>

typedef int Length;

Length a, b, len;
Length numbers[10];

typedef long int64_t;

typedef struct ADate
{
    int month;
    int day;
    int year;
} Date;

int64_t i = 10E9;
Date d = {1, 2, 2022};

typedef char *String[10]; // String is userdefine type

String str = {"Hello", "Typedef"};

/*
{a pointer to pointer} | {a pointer to char array} | {a char array}
 str --> str[0] --> "Hello"
     --> str[1] --> "Typedef"
     --> str[2] --> NULL
 */

typedef struct node 
{
    int date;
    struct node *next;//a pointer to a same struct type "struct node"
} aNode;

int main()
{
    printf("%ld\n", i);
    printf("%i-%i-%i\n", d.year, d.month, d.day);
    printf("%s\n", str[0]);
    printf("%s\n", str[1]);

    return 0;
}
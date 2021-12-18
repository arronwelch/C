/**
 * Exercise 5-12: (page 118 K&R)
 * Extend entab and detab to accept the shorthand
 * 
 * entab -m +n
 * 
 * to mean tap stops every n columns,starting at column m.
 * Choose convenient(for the user)default behavior.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 5 /* maximum line size */
#define TABINC 8  /* default tab increment size */
#define YES 1
#define NO  0

void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

/* replace strings of blanks with tabs */
int main(int argc, char *argv[])
{
    char tab[MAXLINE+1];

    esettab(argc,argv,tab);/* initialize tab stops */
    entab(tab);/* replace blanks with tab */
    return 0;
}

/* extended settab: set tab stops in array tab */
void esettab(int argc, char *argv[], char *tab)
{
    int i, inc, pos;
     
    if (argc <= 1) /* default tab stops */
        for (i = 1 ; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+')/* user provided range */
    {
        pos = atoi(&(*++argv)[1]);//-m
        inc = atoi(&(argv[1][1]));//+n

        for (i = 1; i <= MAXLINE; i++)
            if ( i != pos )
                tab[i] = NO;
            else
            {
                tab[i] = YES;
                pos += inc;                
            }
    }
    else/* user provided tab stops */
    {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO;/* turn off all stops */
        while ( --argc > 0 ) /* walk through argument list */
            pos = atoi(*++argv);
            if ( pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
    }
}

/* entab: replace strings of blanks with tabs and blanks */
void entab(char *tab)
{
    int c, pos;
    int nb = 0; /* 0 of blanks necessary */
    int nt = 0; /* 0 of tabs necessary */

    for (pos = 1; (c = getchar()) != EOF; pos++)
        if (c == ' ')
        {
            if (tabpos(pos, tab) == NO)
                ++nb;  /* increment 0 of blanks */
            else
            {
                nb = 0;/* reset 0 of blanks     */
                ++ nt; /* one more tab          */
            }
        }
        else
        {
            for ( ; nt > 0; nt--)
                putchar('\t'); /* output tab(s)       */

            if (c == '\t')     /* forget the blank(s) */
                nb = 0;
            else               /* output blank(s)     */  
                for ( ; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while ( tabpos(pos, tab) != YES)
                    ++pos;
        }
}

//The source file tabpos.c

//#define MAXLINE 100 /* maximum line size */
//#define YES 1

/* tabpos: determine if pos is at a tab stop */
int tabpos(int pos, char *tab)
{
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos];
}

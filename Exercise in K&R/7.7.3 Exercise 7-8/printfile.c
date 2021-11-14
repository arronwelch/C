
/**
 *  Exercise 7-8:(page 165 K&R)
 *  Write a program to print a set of files, strating each new one on a new page,
 *  with a title and a running page count for each file.
 * 
 *  "args": ["printfile.c"],
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXBOT 3    /* maximum lines at bottom page */
#define MAXHDR 5    /* maximum lines at head of page */
#define MAXLINE 100 /* maximum size of one line */
#define MAXPAGE 66  /* maximum lines on one page */

/* print: print files - each new one on a new page */
int main(int argc, char *argv[])
{
    FILE *fp;
    void mfileprint(FILE * fp, char *fname);

    if (argc == 1) /* no args: print standard input */
        mfileprint(stdin, " ");
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "print: can't open %s\n", *argv);
                exit(1);
            }
            else
            {
                mfileprint(fp, *argv);
                fclose(fp);
            }
    return 0;
}

/* fileprint: print file fname */
void mfileprint(FILE *fp, char *fname)
{
    int lineno, pageno = 1;
    char line[MAXLINE];
    int mheading(char *fname, int pageno);

    lineno = mheading(fname, pageno++);
    while (fgets(line, MAXLINE, fp) != NULL)
    {
        if (lineno == 1)
        {
            fprintf(stdout, "\f");//Form feed: means advance downward to the next "page". 
            lineno = mheading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBOT)
            lineno = 1;
    }
    fprintf(stdout, "\f"); /* page eject after the file */
}

/* heading: put heading and enough blank lines */
int mheading(char *fname, int pageno)
{
    int ln = 3;

    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s page %d\n", fname, pageno);
    while (ln++ < MAXHDR)
        fprintf(stdout, "\n");
    return ln;
}


/*
 new tips:

https://stackoverflow.com/questions/3091524/what-are-carriage-return-linefeed-and-form-feed

Carriage return means to return to the beginning of the current line without advancing downward. The name comes from a printer's carriage, 
as monitors were rare when the name was coined. This is commonly escaped as \r, abbreviated CR, and has ASCII value 13 or 0x0D.

Linefeed means to advance downward to the next line; however, it has been repurposed and renamed. Used as "newline", 
it terminates lines (commonly confused with separating lines). This is commonly escaped as \n, abbreviated LF or NL, 
and has ASCII value 10 or 0x0A. CRLF (but not CRNL) is used for the pair \r\n.

Form feed means advance downward to the next "page". It was commonly used as page separators, 
but now is also used as section separators. (It's uncommonly used in source code to divide logically independent functions or groups of functions.) 
Text editors can use this character when you "insert a page break". This is commonly escaped as \f, abbreviated FF, and has ASCII value 12 or 0x0C.

*/
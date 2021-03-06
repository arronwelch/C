/**
 * This program reads input lines from standard input and prints
 * each input line,followed by just some protions of the line, to
 * the standard output.
 *
 * The first input is a lint of column numbers, which ends with a
 * negative number. The column numbers are paired and specify
 * ranges of columns from the input line that are to be printed.
 * For example, 0 3 10 12 -1 indicates that only columns 0 through 3
 * and columns 10 through 12 will be printed.
 * */

/**
 * 4 9 12 20 -1
abcdefghijklmnopqrstuvwxyz
Original input: abcdefghijklmnopqrstuvwxyz
Rearranged line: efghijmnopqrstu
Hello there, how are you?
Original input: Hello there, how are you?
Rearranged line: o ther how are
I am fine, thanks.
Original input: I am fine, thanks.
Rearranged line:  fine,hanks.
See you!
Original input: See you!
Rearranged line: you!
Bye
Original input: Bye
Rearranged line: you!
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20    /* max # of columns to process */
#define MAX_INPUT 1000 /* max len of input & output lines */

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void)
{
    int n_columns;          /* # of columns to process */
    int columns[MAX_COLS];  /* the columns to process */
    char input[MAX_INPUT];  /* array for input line */
    char output[MAX_INPUT]; /* array for output line */

    /*
    **  Read the list of column numbers
    */
    n_columns = read_column_numbers(columns, MAX_COLS);

    /*
    **  Read, process and print the remaining lines of input
    */
    while ( gets(input) != NULL)
    {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}

/*
** Read the list of column numbers, ignoring any beyond the specified maximum.
*/
int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    /*
    **  Get the numbers, stopping at eof or when a number is < 0.
    */
    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
    {
        num += 1;
    }

    /*
    **  Make sure we have an even number of inputs, as they are supposed to be paired.
    */
    if (num % 2 != 0)
    {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    /*
    **  Discard the rest of the line that contained the final number.
    */
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        ;
    }

    return num;
}

/*
**  Process a line of input by concatenating the characters from the indicated columns.
**  The output line is the NUL terminated.
*/
void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int col;        /* subscript for columns array */
    int output_col; /* output column counter */
    int len;        /* length of input line */

    len = strlen(input);
    output_col = 0;

    /*
    **  Process each pair of column numbers.
    */
    for (col = 0; col < n_columns; col += 2)
    {
        int nchars = columns[col + 1] - columns[col] + 1;
        // nchars = columns[0+1] - columns[0] + 1
        // nchar = 3 - 0 + 1  == 4 // count character
/*
 * For example, 0 3 10 12 -1 indicates that only columns 0 through 3
 * and columns 10 through 12 will be printed.
 */

        /*
        **  If the input line isn't this long or the output array is full, we're done.
        */
        if (columns[col] >= len || output_col == MAX_INPUT - 1)
        // [columns[col]](input copy start index) over the length of input
        // [output_col](output copy start index) over the length of input
        {
            break;
        }

        /*
        **  If there isn't room in the output array, only copy what will fit.
        */
        if (output_col + nchars > MAX_INPUT - 1)
        {
            nchars = MAX_INPUT - output_col - 1;// ???
        }
        // 0 + 2000 > 1000 - 1
        // nchars = 999 - 0
        // nchars = MAX_INPUT -output_col;
        // nchars = 1000 - 0
        if (columns[col] + nchars > MAX_INPUT - 1)
        {
            nchars = MAX_INPUT - columns[col];
        }

        /*
        **  Copy the relevent data.
        */
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
}

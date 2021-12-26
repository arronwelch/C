
#include <stdio.h>

int main()
{
    const int size = 3;
    int board[size][size];
    int i, j;
    int numofXLn;
    int numofOLn;
    int numofXCol;
    int numofOCol;
    int result = -1; // -1:no one win; 1 : 'X' win; 0 : 'O' win.

    // read Matrix
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    // check Line
    for (i = 0; i < size && result == -1; i++)
    {
        numofOLn = numofXLn = numofOCol = numofXCol = 0;
        for (j = 0; j < size; j++)
        {
            if (board[i][j] == 1) // 'X'
            {
                numofXLn++;
            }
            else // 'O'
            {
                numofOLn++;
            }

            if (board[j][i] == 1) // 'X'
            {
                numofXCol++;
            }
            else // 'O'
            {
                numofOCol++;
            }
        }
        if (numofOLn == size || numofOCol == size)
        {
            result = 0;
        }
        else if (numofXLn == size || numofXCol == size)
        {
            result = 1;
        }
    }
    
    //check corner
    numofOLn = numofXLn = numofOCol = numofXCol = 0;
    for ( i=0; i< size; i++)
    {
        if ( board[i][i] == 1)
        {
            numofXLn ++;
        }
        else
        {
            numofOLn ++;
        }

        if ( board[i][size-i-1] == 1)
        {
            numofXCol ++;
        }
        else
        {
            numofOCol ++;
        }
    }
    if ( numofOLn == size || numofOCol == size)
    {
        result = 0;
    }
    else if ( numofXLn == size || numofXCol == size)
    {
        result = 1;
    }

    //print who win?
    printf("result = %d\n",result);

    return 0;
}

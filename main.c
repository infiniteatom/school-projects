#include <stdio.h>
#include <stdlib.h>

#define N   8

int     board[N];

void    printBoard()
{
    static int solutions = 1;

    printf("%d\n", solutions);
    ++solutions;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (j == board[i])
                printf("# ");
            else
                printf(". ");
        printf("\n");
    }
}

int place(int row, int column)
{
    for(int i = 0; i < row; ++i)
    {
        if(board[i] == column)
            return 0;
        else if(abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void    backTracking(int row)
{
    for(int column = 0; column < N; ++column)
    {
        if(place(row, column))
        {
            board[row] = column;
            if (row == N - 1)
                printBoard();
            else
                backTracking(row + 1);
        }
    }
}

int     main(void)
{
    backTracking(0);

    return (0);
}

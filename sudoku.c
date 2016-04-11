#include <stdio.h>
#include <stdlib.h>

int     board[9][9];

int     isAvailable(int row, int col, int num)
{
    int rowStart = row - (row % 3);
    int colStart = col - (col % 3);

    for (int i = 0; i < 9; i++)
        if (board[row][i] == num ||
            board[i][col] == num ||
            board[rowStart + (i % 3)][colStart + (i / 3)] == num)
            return (0);
    return (1);
}

int     backTracking(int row, int col)
{
    if(row < 9 && col < 9)
    {
        if(board[row][col] != 0)
        {
            if((col + 1) < 9)
                return backTracking(row, col + 1);
            else if ((row + 1) < 9)
                return backTracking(row + 1, 0);
            else return 1;
        }
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                if(isAvailable(row, col, i))
                {
                    board[row][col] = i;
                    if ((col + 1) < 9)
                    {
                        if (backTracking(row, col + 1))
                            return 1;
                        else
                            board[row][col] = 0;
                    }
                    else if((row + 1) < 9)
                    {
                        if(backTracking(row + 1, 0))
                            return 1;
                        else
                            board[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

void    printSudoku()
{
    printf("+- - -+- - -+- - -+\n");
    for (int i = 0; i < 9; i++)
    {
        printf("|");
        for (int j = 0; j < 9; j++)
        {
            printf("%d", board[i][j]);
            if (j % 3 != 2)
                printf(" ");
            if ((j + 1) % 3 == 0)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
            printf("+- - -+- - -+- - -+\n");
    }
}

void    scanFile(const char file[])
{
    FILE    *fp;

    fp = fopen(file, "r");
    for (int  i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            fscanf(fp, "%d", &board[i][j]);
    fclose(fp);
}

int     main(void)
{
    scanFile("sudoku.txt");
    if (backTracking(0, 0))
        printSudoku();
    else
        printf("No solutions");
    return (0);
}

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

void    backTracking(int row)
{
}

void    printSudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d", board[i][j]);
        printf("\n");
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
    printSudoku();
    return (0);
}

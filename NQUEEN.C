#include <stdio.h>
#include <conio.h>
#define N 4

int board[N][N];

void printSolution()
{
    int i, j;
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
    getch();
}
// check if a queen can be placed at board[row][col]
int isSafe(int row, int col)
{
    int i, j;
    // check left side of the row
    for (i = 0; i < col; ++i)
        if (board[row][i])
            return 0;
    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    // check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j])
            return 0;

    return 1;
}
// solve N-Queens problem using back tracking
int NQP(int col)
{
    int i, res = 0;
    if (col >= N)
    {
        printSolution();
        return 1; // return true to show at least one soln exist
    }
    for (i = 0; i < N; ++i)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1; // Place Queen
            res = NQP(col + 1) || res;
            board[i][col] = 0; // backtrack
        }
    }
    return res;
}
void main()
{
    // clrscr();
    if (!NQP(0))
        printf("Solution doesn't exist \n");
}
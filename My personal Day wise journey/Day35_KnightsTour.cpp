#include <bits/stdc++.h>
#define N 8
using namespace std;

bool isSafe(int x, int y, int mat[N][N])
{
    return (x < N && y < N && mat[x][y] == -1 && x >= 0 && y >= 0);
}

int solveUtil(int mat[N][N], int xarr[], int yarr[], int stepCount, int x, int y)
{

    if (stepCount == N * N)
    {
        return 1;
    }
    for (int step = 0; step < 8; step++)
    {
        int nextX = x + xarr[step];
        int nextY = y + yarr[step];
        if (isSafe(nextX, nextY, mat))
        {
            mat[nextX][nextY] = stepCount;
            if (solveUtil(mat, xarr, yarr, stepCount + 1, nextX, nextY) == 1)
            {
                return 1;
            }
            else
                mat[nextX][nextY] = -1; //backtrack
        }
    }
    return 0;
}

void solve()
{
    int x[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int mat[N][N];
    memset(mat, -1, sizeof(mat));
    mat[0][0] = 0;
    if (!solveUtil(mat, x, y, 1, 0, 0))
    {
        cout << "No solution exissts\n";
    }
    else
    {
        //lets print matrix
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << setw(2) << " " << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}

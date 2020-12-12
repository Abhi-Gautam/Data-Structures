#include <bits/stdc++.h>
using namespace std;
#define M 5
#define N 5
struct queueNode
{
    int i, j, distance;
};
int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};
bool isValid(int i, int j)
{
    if ((i < 0 || i > M - 1) || (j < 0 || j > N - 1))
        return false;
    return true;
}
bool isSafe(int i, int j, char matrix[][N], int output[][N])
{
    if (matrix[i][j] != 'O' || output[i][j] != -1)
        return false;
    return true;
}
void findDistance(char matrix[][N])
{
    int output[M][N];
    queue<queueNode> q;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            output[i][j] = -1;
            if (matrix[i][j] == 'G')
            {
                queueNode pos = {i, j, 0};
                q.push(pos);
                output[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        queueNode curr = q.front();
        int x = curr.i, y = curr.j, dist = curr.distance;
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(x + row[i], y + col[i], matrix, output) && isValid(x + row[i], y + col[i]))
            {
                output[x + row[i]][y + col[i]] = dist + 1;
                queueNode pos = {x + row[i], y + col[i], dist + 1};
                q.push(pos);
            }
        }
        q.pop();
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << std::setw(3) << output[i][j];
        cout << endl;
    }
}
int main()
{
    char matrix[][N] =
        {
            {'O', 'O', 'O', 'O', 'G'},
            {'O', 'W', 'W', 'O', 'O'},
            {'O', 'O', 'O', 'W', 'O'},
            {'G', 'W', 'W', 'W', 'O'},
            {'O', 'O', 'O', 'O', 'G'}};
    findDistance(matrix);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int minSumPath(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + minSumPath(i - 1, j, dp, grid);
    int right = grid[i][j] + minSumPath(i, j - 1, dp, grid);

    return dp[i][j] = min(up, right);
}

int Getpath(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minSumPath(n - 1, m - 1, dp, grid);
}

int minPathSum(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = mat[i][j];
            }
            else
            {
                int up = mat[i][j];
                if (i > 0)
                {
                    up += dp[i - 1][j];
                }
                else
                {
                    up += 1e9;
                }

                int left = mat[i][j];
                if (j > 0)
                {
                    left += dp[i][j - 1];
                }
                else
                {
                    left += 1e9;
                }

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[i][j];
            }
            else
            {
                int up = grid[i][j];
                if (i > 0)
                {
                    up += prev[j];
                }
                else
                {
                    up += 1e9;
                }

                int left = grid[i][j];
                if (j > 0)
                {
                    left += temp[j - 1];
                }
                else
                {
                    left += 1e9;
                }

                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }
    return prev[m - 1];
}
int main()
{
    vector<vector<int>> mat{{5, 9, 6}, {11, 5, 2}};
    int n = mat.size();
    int m = mat[0].size();

    cout << Getpath(n, m, mat);
}
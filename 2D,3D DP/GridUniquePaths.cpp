#include <bits/stdc++.h>
using namespace std;

// TC-> O(N*M) SC-> O(N-1)+O(M-1)+O(N*M)
int solve(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);
    return dp[i][j] = up + left;
}

int UniquePath(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, dp);
}

// TC-> O(N*M) SC->O(N*M)

int solve2(int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}

int uniquePaths2(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    return solve2(n, m, dp);
}

//TC-> O(N*M) SC-> O(N)
int uniquePaths3(int n,int m)
{
       vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << UniquePath(n, m);
}
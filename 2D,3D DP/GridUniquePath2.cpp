#include <bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid)
{
    if(i==0 && j==0 && grid[i][j]==1)return 1;
    if(i<0 || j<0)return 0;
    if(i==0 && j==0)return 1;
    if(dp[i][j]==1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int up = solve(i-1,j,dp,grid);
    int left = solve(i,j-1,dp,grid);
    return dp[i][j] = up+left; 
}

int uniquePath(int n,int m,vector<vector<int>>&grid)
{
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,dp,grid);
}



int main()
{
    vector<vector<int>> arr{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int n = arr.size();
    int m = arr[0].size();

    cout<<uniquePath(n,m,arr);
}
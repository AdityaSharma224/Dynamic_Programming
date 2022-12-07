#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &height, int k, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int miniSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jump = solve(n - j, height, k, dp) + abs(height[n] - height[n - j]);
            miniSteps = min(jump, miniSteps);
        }
    }
    return dp[n] = miniSteps;
}
int minimizeCost(vector<int> &height, int n, int k)
{

    vector<int> dp(n, -1);
    return solve(n - 1, height, k, dp);
}

int tabulation(int n,vector<int>&height,vector<int>&dp,int k)
{
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int minSteps = INT_MAX;

        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int jump = dp[i-j]+abs(height[i]-height[i-j]);
                minSteps = min(jump,minSteps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}


int main()
{
    vector<int>arr = {10,30,40,50,20};
    int k = 3;
    int n = arr.size();

    cout<<minimizeCost(arr,n,k)<<endl;
    vector<int>dp(n+1,0);
    cout<<tabulation(n,arr,dp,k)<<endl;
}
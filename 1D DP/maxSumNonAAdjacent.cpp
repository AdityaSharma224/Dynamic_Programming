#include <bits/stdc++.h>
using namespace std;

//TC-> O(N) SC-> O(N)
int solve(int n, vector<int> &arr, vector<int> &dp)
{
    if (n == 0)
        return arr[n];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int pick = arr[n] + solve(n - 2, arr, dp);
    int nonpick = 0 + solve(n - 1, arr, dp);

    return dp[n] = max(pick, nonpick);
}

int maxSum(vector<int> &arr, int n)
{
    vector<int> dp(n, -1);
    return solve(n - 1, arr, dp);
}


//TC-> O(N) SC-> O(N)
int solve2(vector<int>&arr,vector<int>&dp,int n)
{
    dp[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        int pick = arr[i];
        if(i>1)
        {
            pick = pick + dp[i-2];
        }
        int nonpick = 0 + dp[i-1];

        dp[i] = max(pick,nonpick);
    }
    return dp[n-1];

}

int maxSum2(vector<int>&arr,int n)
{
    vector<int>dp(n,-1);
    return solve2(arr,dp,n);
}

//TC-> O(N) SC-> O(1)

int maxSum3(vector<int>&arr,int n)
{
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1;i<n;i++)
    {
        int pick = arr[i];
        if(i>1)
        {
            pick +=prev2;
        }
        int nonpick = 0+prev;

        int curr = max(pick,nonpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}




int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int n = arr.size();
    cout << maxSum3(arr, n);
}
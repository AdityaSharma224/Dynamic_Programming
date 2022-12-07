#include<bits/stdc++.h>
using namespace std;

//Memoization TC-> O(N) SC-> O(N)
int fib(int n,vector<int>&dp)
{
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = fib(n-1,dp)+fib(n-2,dp);
}

//Tabulation TC-> O(N) SC-> O(N)
int fib2(int n,vector<int>&dp)
{
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//Space Optimization TC->O(N) SC-> O(1)
int fib3(int n)
{
    int prev2=0;
    int prev=1;

    for(int i=2;i<=n;i++)
    {
        int curr = prev2+prev;
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int main()
{
    int n;
    cin>>n;

    vector<int>dp(n+1,-1);
    cout<<fib(n,dp)<<endl;
    cout<<fib2(n,dp)<<endl;
    cout<<fib3(n)<<endl;
    return 0;
}
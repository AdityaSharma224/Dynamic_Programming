#include<bits/stdc++.h>
using namespace std;

// Memoization  TC-> O(1) SC-> O(N)
int solve(int n,vector<int>&arr,vector<int>&dp)
{
    if(n==0)return 0;
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int jump2 = INT_MAX;
    int jump1 = solve(n-1,arr,dp)+abs(arr[n]-arr[n-1]);

    if(n>1)
    {
        jump2 = solve(n-2,arr,dp)+abs(arr[n]-arr[n-2]);
    }
    return dp[n] = min(jump1,jump2);
}

//tabulation
int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}

// space optimization
int main()
{
    vector<int> height{30,10,60,10,60,50};
     int n=height.size();
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++)
    {
        int jump2 = INT_MAX;
        int jump1 = prev+abs(height[i]-height[i-1]);
        if(i>1)
        {
            jump2 = prev2+abs(height[i]-height[i-2]);
        }
        int curr = min(jump1,jump2);
        prev2=prev;
        prev=curr;
    }
    cout<<prev;
}
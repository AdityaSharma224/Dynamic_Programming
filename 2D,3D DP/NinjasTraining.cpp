#include<bits/stdc++.h>
using namespace std;


//TC->O(N*4*3) SC-> O(N)+O(N*4)
int solve(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp)
{
    if(dp[day][last]!=-1)
    {
        return dp[day][last];
    }


    if(day==0)
    {
        int maxi = 0;
        for(int i=0;i<=2;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,points[0][i]);
            }
        }
        return dp[day][last]=maxi;
    }

    int maxi = 0;
    for(int i=0;i<=2;i++)
    {
        if(i!=last)
        {
            int activity = points[day][i] + solve(day-1,i,points,dp);
            maxi=max(maxi,activity);
        }
    }
    return dp[day][last] = maxi;
}

int ninjasTraining(vector<vector<int>>&points,int n)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(n-1,0,points,dp);
}

int main()
{
    vector<vector<int>>points{{10,40,70},
    {20,50,80},
    {30,60,90}};
    int n = points.size();
    cout<<ninjasTraining(points,n);
}
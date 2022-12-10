#include<bits/stdc++.h>
using namespace std;

//TC-> O(N) SC-> O(1)


int solve(vector<int>&arr,int n)
{
    int prev2 = arr[0];
    int prev = 0;

    for(int i=2;i<n;i++)
    {
        int pick = arr[i];
        if(i>1)
        {
            pick+=prev2;
        }
        int nonpick = 0 + prev;
        int curr = max(pick,nonpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

int maxSum(vector<int>&arr,int n)
{
    vector<int>temp1;
    vector<int>temp2;

    if(n==1)return arr[0];

    for(auto it:arr)
    {
        if(it!=0)temp1.push_back(it);
        if(it!=n-1)temp2.push_back(it);
    }
    int ans = solve(temp1,n);
    int ans2 = solve(temp2,n);
    return max(ans,ans2);
}

int main()
{
    vector<int>arr{2,1,4,9};
    int n = arr.size();
    cout<<maxSum(arr,n);
}
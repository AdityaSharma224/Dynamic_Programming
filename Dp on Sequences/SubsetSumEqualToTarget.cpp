#include <bits/stdc++.h>
using namespace std;
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}
bool isSubsetSum(vector<int> arr, int k)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);
}

int main()
{
    vector<int> arr{3, 34, 4, 12, 5, 2};
    int k = 30;
    bool ans = isSubsetSum(arr, k);
    if (ans)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
}
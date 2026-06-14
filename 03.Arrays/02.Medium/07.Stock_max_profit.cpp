#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int stockBuySell(vector<int> arr, int n){

        int profit=0,mini=INT_MAX;

        for(int i=0;i<n;i++)
        {
            profit=max(profit,arr[i]-mini);
            mini=min(mini,arr[i]);
        }

        return profit;
        
    }
};

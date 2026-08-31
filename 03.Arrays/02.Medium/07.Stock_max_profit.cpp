#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int stockBuySell(vector<int> arr, int n){

        int profit=0,mini=arr[0];

        for(int i=1;i<n;i++)
        {
            profit=max(profit,arr[i]-mini);
            mini=min(mini,arr[i]);
        }

        return profit;
        
    }
};

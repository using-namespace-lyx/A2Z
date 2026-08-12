#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> s;
    int cnt;
    StockSpanner() {
        
        cnt=0;
        
    }
    
    int next(int price) {

        while(!s.empty() && s.top().first <= price)
        {
            s.pop();
        }

        int pge=s.empty()?-1:s.top().second;

        s.push({price,cnt});

        int ans=cnt-pge;

        cnt++;
        return ans;

        
    }
};

/*
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
*/
// Brute

class StockSpanner {
public:
    vector<int> nums;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=0;

        nums.push_back(price);

        int n=nums.size();

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<=price)
            count++;

            else
            break;
        }

        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
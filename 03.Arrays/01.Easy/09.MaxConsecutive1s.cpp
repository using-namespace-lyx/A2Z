#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxi=0,count=0;

        for(int num:nums)
        {
            if(num==1)
            {
                count++;
                maxi=max(maxi,count);
            }
            else
            count=0;
        }

        return maxi;
        
    }
};
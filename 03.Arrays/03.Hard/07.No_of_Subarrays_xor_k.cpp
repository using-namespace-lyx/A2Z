#include<bits/stdc++.h>
using namespace std;

int SubArrXorK(vector<int> nums,int k)
{
    int n=nums.size();
    int count=0;

    for(int i=0;i<n;i++)
    {
        int xorr=0;
        for(int j=i;j<n;j++)
        {
            xorr^=nums[j];
            if(xorr==k)
            count++;

        }
    }

    return count;
}

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {

        int xorr=0;
        map<int,int> mpp;
        mpp[0]=1;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            xorr^=nums[i];
            int remain=xorr^k;
            count+=mpp[remain];
            mpp[xorr]++;
        }

        return count;
        
    }
};
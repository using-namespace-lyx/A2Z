#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> nums)
{
    int maxi=INT_MIN;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>maxi)
        {
            maxi=nums[i];
        }
    }

    return maxi;
}
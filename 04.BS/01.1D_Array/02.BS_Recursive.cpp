#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> nums,int low, int high, int target)
{
    if(low>high) return -1;

    int mid=low+(high-low)/2;

    if(nums[mid]==target) return mid;

    else if(nums[mid]<target)
    return bs(nums,mid+1,high,target);

    else
    return bs(nums,low,mid-1,target);
}
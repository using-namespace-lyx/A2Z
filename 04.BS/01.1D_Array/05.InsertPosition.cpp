#include<bits/stdc++.h>
using namespace std;

int insertPosition(vector<int> nums, int x)
{
    // Find the lowest index position to insert x in a sorted array nums
    return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
}
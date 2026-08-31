#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> s;

        for(int num:nums)
        s.insert(num);

        int index=0;
        for(int num:s)
        nums[index++]=num;

        return index;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=0;
        for(int q=1;q<nums.size();q++)
        {
            if(nums[p]!=nums[q])
                nums[++p]=nums[q];
        }

        return p+1;
        
    }
};
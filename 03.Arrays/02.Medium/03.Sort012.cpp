#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {

        sort(nums.begin(),nums.end());
       
        
    }
};

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {

        int zeroes=0,ones=0,twos=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            switch(nums[i])
            {
                case 0: zeroes++; break;
                case 1: ones++; break;
                case 2: twos++; break;
            }
        }

        for(int k=0;k<n;k++)
        {
            if(zeroes>0)
            {
                zeroes--;
                nums[k]=0;
            }

            else if(ones>0)
            {
                ones--;
                nums[k]=1;
            }

            else
            {
                nums[k]=2;

            }
            
        }
        
    }
};
/*
The key idea is to divide the array into four regions using three pointers:

0 to low-1 → all 0s
low to mid-1 → all 1s
mid to high → unknown elements
high+1 to n-1 → all 2s

We process the unknown region using mid.

For every nums[mid]:

If it is 0, swap it with nums[low] and move both low and mid.
If it is 1, it is already in the correct middle region, so just move mid.
If it is 2, swap it with nums[high] and move high. We don't move mid because the element swapped from high has not been checked yet.

This allows us to sort the array in a single pass without using any extra array.*/
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {

        int n=nums.size();
        int low=0,mid=0,high=n-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
                
            }

            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};
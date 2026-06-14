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
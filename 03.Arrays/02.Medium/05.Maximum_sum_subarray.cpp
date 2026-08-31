#include<bits/stdc++.h>
using namespace std;
/*
/*
QUESTION:-
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
*/

/*
APPROACH:-
-> Initialize two variables: maxSum and currentSum. Set both variables to the first element of the array.
-> Iterate through the array starting from the second element:
    Update currentSum by adding the current element to it.
    If currentSum becomes negative, reset it to 0. This step ensures that we consider only the subarrays with positive sums.
    Update maxSum by taking the maximum value between maxSum and currentSum. This keeps track of the maximum subarray sum encountered so far.
-> After the iteration, the maxSum variable will hold the largest sum of any subarray.
-> Return the maxSum as the result.
*/
// Brute force

int maxsum(vector<int> &nums)
{
    int sum=0,n=nums.size(),maxi=INT_MIN,start=0,end=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
            if(sum>maxi)
            {
                start=i;
                end=j;
                maxi=sum;
            }

            
        }
    }
}

// CODE:-
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum=0,n=nums.size();
        int arrstart,start,arrEnd;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++ )
        {
            if(sum==0)
            {
                start=i;
            }
            sum+=nums[i];

            if(sum>maxi)
            {
                maxi=sum;
                arrstart=start;
                arrEnd=i;
            }

            if(sum<0)
            {
                sum=0;
            }
        }

        return maxi;
        
    }
};

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)
#include<bits/stdc++.h>
using namespace std;

/*
QUESTION:-

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/



// BRUTE FORCE
bool ls(vector<int> &nums, int x)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==x) return true;
    }

    return false;
}
int lcsbrute(vector<int> &nums)
{
    int count=0,maxcount=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        count=1;
        int x=nums[i];

        while(ls(nums,x+1))
        {
            count++;
            x++;
        }

        maxcount=max(maxcount,count);
    }

    return maxcount;
}


int lcssort(vector<int> &nums)
{
    int n=nums.size();
    if(n==0) return 0;

    sort(nums.begin(),nums.end());
    int count=0,len=1,lastsmall=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==lastsmall+1)
        {
            lastsmall=nums[i];
            count++;
        }

        else if(nums[i]!=lastsmall)
        {
            count=1;
            lastsmall=nums[i];

        }

        len=max(len,count);

    }

    return len;
}
/*

APPROACH:-

To find the length of the longest consecutive elements sequence, we can follow these steps:

1. Create a set to store all the elements of the array.
2. Iterate through the array and insert each element into the set.
3. For each element, check if its previous consecutive element (num-1) exists in the set. If it does not exist, it means the current element is the starting element of a sequence.
4. For each starting element, keep incrementing the current element (num+1) and checking if it exists in the set. This will help find the consecutive elements in the sequence.
5. Keep track of the maximum length of consecutive elements encountered.
6. Return the maximum length as the result.

*/

// CODE:
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp.insert(nums[i]);
    }
    int ans = 0;
   for(int el:mp)
   {
    if(mp.find(el-1)==mp.end())
    {
        int x=el;
        int count=1;
        while(mp.find(x+1)!=mp.end())
        {
            x++;
            count++;
        }

    }
   }
    return ans;
}

// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(n), as we are using a set to store the elements of the array.

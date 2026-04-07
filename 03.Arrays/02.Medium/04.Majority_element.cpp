#include<bits/stdc++.h>
using namespace std;
/*
QUESTION:-
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*
APROACH:-
-> Initialize two variables: candidate and count. Set candidate to the first element of the array, and count to 1.
-> Iterate through the array starting from the second element:
    If the current element is equal to the candidate, increment the count by 1.
    If the current element is different from the candidate, decrement the count by 1.
    If the count becomes 0, update the candidate to the current element and set the count to 1 again.
-> After the iteration, the candidate variable will hold the majority element.
Return the candidate as the result.
*/
// BRUTE FORCE
int majorityElement(vector<int> &nums)
{
    int n=nums.size(),count=0;
    for(int i=0;i<n;i++)
    {
        count=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==nums[i])
            count++;
        }

        if(count>n/2)
        return nums[i];

    }
}

//BETTER SOLUTION : Hashing

int majority(vector<int> &nums)
{
    unordered_map<int,int> m;
    int n=nums.size();

    for(int i=0;i<n;i++)
    {
        m[nums[i]]++;

        if(m[nums[i]]>n/2)
            return nums[i];
    }

    return -1;
}

// TC: O(N) for unordered_map or O(log N) for map
//SC: O(N)


// CODE:-
// More's voting algorithm
int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int n=nums.size(),count=0;
    int vote = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (vote <= 0)
            candidate = nums[i];
        if (nums[i] == candidate)
            vote++;
        else
            vote--;
    }
    // return candidate; if the problem clearly states there will be an element with >n/2 else to verify

    for(int i=0;i<n;i++)
    {
        if(nums[i]==candidate) count++;
    }

    if(count>n/2) return candidate;
    else return -1;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)
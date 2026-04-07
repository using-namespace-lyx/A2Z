/*
QUESTION:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

APPROACH:
To merge overlapping intervals, we can follow these steps:
1. Sort the intervals based on the start time.
2. Initialize a vector `ans` to store the merged intervals.
3. Add the first interval from the sorted intervals to the `ans` vector.
4. Iterate through the remaining intervals:
   - If the start time of the current interval is less than or equal to the end time of the last interval in the `ans` vector, it means they overlap. Update the end time of the last interval in the `ans` vector if necessary.
   - If the start time of the current interval is greater than the end time of the last interval in the `ans` vector, it means they don't overlap. Add the current interval to the `ans` vector.
5. Return the `ans` vector as the merged non-overlapping intervals.

CODE:
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i=0;i<nums.size();i++)
    {
        if(res.empty() || nums[i][0]>res.back()[1])
        {
            res.push_back(nums[i]);
        }
        else
        {
            res.back()[1]=max(res.back()[1],nums[i][1]);
        }

        
    }

    return res;

}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high)
    {
        vector<int> temp;
        int i=low, j=mid+1;

        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid)
        {
            temp.push_back(nums[i]);
                i++;
        }
        while(j<=high)
        {
            temp.push_back(nums[j]);
                j++;
        }

        for(int i=low;i<=high;i++)
        nums[i]=temp[i-low];
    }
    void mergeSortHelper(vector<int> &nums, int low,int high)
    {
        if(low>=high) return;

        int mid=low+(high-low)/2;

        mergeSortHelper(nums,low,mid);
        mergeSortHelper(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> mergeSort(vector<int>& nums) {
        mergeSortHelper(nums,0,nums.size()-1);
        return nums;




        

    }
};
/*
MERGE SORT
────────────────────────────────

Paradigm:
Divide and Conquer

Core:
Divide → recursively sort → merge

Base case:
low >= high

Mid:
low + (high-low)/2

Recursion:
[low...mid]
[mid+1...high]

Merge:
Two pointers

Stable:
YES (with <= during merge)

In-place:
NO (standard array implementation)

Best:
O(n log n)

Average:
O(n log n)

Worst:
O(n log n)

Auxiliary space:
O(n)

Recursion stack:
O(log n)

Recurrence:
T(n) = 2T(n/2) + O(n)

Adaptive:
NO (standard)

Major strengths:
Guaranteed O(n log n)
Stable
Excellent for linked lists
Excellent for external sorting

Major weakness:
O(n) extra space for arrays

Important applications:
Inversion counting
K-way merge
External sorting
Linked-list sorting*/
#include<bits/stdc++.h>
using namespace std;


bool isSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If any element is smaller than the previous one, return false
            if (arr[j] < arr[i]) 
                return false;
        }
    }

    return true; // Return true if no unsorted elements are found
}


bool isSorted(vector<int> nums)
{
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<nums[i-1]) return false;
    }

    return true;
}
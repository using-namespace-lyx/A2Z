#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> nums, int x)
{
    // Lower bound of a number x in a sorted array is the lowest index of the number such that arr[index]>=x
    // if a num greater than or equal to x is not present return size (n) { hypothetical index aftr last index (n-1)}

    // Basic binary search

    int n=nums.size()-1;
    int ans=n ;// Assume a value >=x is not there

    int low=0,high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }

    }

    return ans;

}

// How to return answer without storing ans. Its based on intutition of criss cross, when low and high swap if inititally low was holding answer it will be high and vice versa
// Lets take an example
/*
    Consider
    nums=[1 1 2 3 4 5 6 7 8]

    consider x=6
            N N N N N N Y Y Y
        nums=[1 1 2 3 4 5 6 7 8]
    So all nos are not possible answers, yes are possible in the event of binary search
    so high index is possibe here after criss cross low comes here so return low

*/

int lowerBound(vector<int> nums, int x)
{
    int low=0,high=nums.size()-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]>=x)
        {
            high=mid-1;
        }

        else
        {
            low=mid+1;
        }
    }

    return low;
}

// C++ STL has an inbuilt function

int lowerBound(vector<int> nums, int x)
{
    return ( (lower_bound(nums.begin(),nums.end(),x) ) - nums.begin() );

    // lower bound within the arr range of x
    // lower_bound returns an iterayor to index , to get index int subtract it from nums.begin()
}


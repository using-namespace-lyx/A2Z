#include<bits/stdc++.h>
using namespace std;


// Upper bound is very similar to lower bond
// Here we are looking for lowest index oin an array  such that nums[index]> x
// It is strictly greater, thats the dfference
// It is easy to obtain code from lower bound just by changing>= sign to >

int upperBound(vector<int> nums, int x)
{
    // Upper bound of a number x in a sorted array is the lowest index of the number such that arr[index]>x
    // if a num greater than or equal to x is not present return size (n) { hypothetical index aftr last index (n-1)}

    // Basic binary search

    int n=nums.size()-1;
    int ans=n ;// Assume a value >=x is not there

    int low=0,high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]>x) // here replace >= with >
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
              N N N N N N N Y Y
        nums=[1 1 2 3 4 5 6 7 8]
    So all nos are not possible answers, yes are possible in the event of binary search
    so high index is possibe here after criss cross low comes here so return low

    // lower bound:6
    // Upper bound:7

*/

int upperBound(vector<int> nums, int x)
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

int upperBound(vector<int> nums, int x)
{
    return ( (upper_bound(nums.begin(),nums.end(),x) ) - nums.begin() );

    // upper bound within the arr range of x
    // upper_bound returns an iterator to index , to get index int subtract it from nums.begin()
}


#include<bits/stdc++.h>
using namespace std;

// Brute

int second(vector<int> nums)
{
    int n=nums.size();

    sort(nums.begin(),nums.end());

    int second=-1;
    
    int largest=nums[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]!=largest)
        {
            second=nums[i];
            break;
        }
    }

    return second;
}


// Better

int second(vector<int> nums)
{
    int maxi=INT_MIN;

    for(int num:nums)
    {
        maxi=max(maxi,num);
    }
    int sec=-1;
    for(int num:nums)
    {
        if(num> sec && num<maxi)
        {
            sec=num;
        }

    }

    return sec;
}

// Optimal

int second(vector<int> nums)
{
    int n=nums.size();

    int maxi=-1,sec=-1;

    for(int i=0;i<n;i++)
    {
        if(nums[i]>=maxi)
        {
            sec=maxi;
            maxi=nums[i];
        }

        else if(nums[i]> sec)
        {
            sec=nums[i];
        }
    }

    return sec;
}


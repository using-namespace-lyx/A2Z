#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){

        int maxi=0,n=nums.size();

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];

                if(sum==k)
                {
                maxi=max(maxi,j-i+1);
                }
            }

            
        }

        return maxi;
        
    }
};

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){

        unordered_map<int,int> mpp;
        int n=nums.size(),sum=0,maxi=0;
        mpp[0] = -1;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int remaining=sum-k;

            if(mpp.find(remaining)!=mpp.end())
            {
                maxi=max(maxi,i-mpp[remaining]);
            }

            if(mpp.find(sum)==mpp.end())
            {
                mpp[sum]=i;
            }

        }

        return maxi;
        
    }
};

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){

        int i=0,j=0,sum=0,maxi=0,n=nums.size();

        while(j<n)
        {
            sum+=nums[j];

            while(sum>k)
            {
                sum-=nums[i];
                i++;
                
            }

            if(sum==k)
            {
                maxi=max(maxi,j-i+1);
            }
            

            j++;
        }

        return maxi;
        
    }
};

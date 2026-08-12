#include<bits/stdc++.h>
using namespace std;

// Find Next Greatest Element for each element in the array , -1 else

// Brute force - O(n*n)

 vector<int> nextLargerElement(vector<int> arr) {

        vector<int> nge;
        int n=arr.size();

        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i])
                {
                    nge.push_back(arr[j]);
                    break;

                }

                
            }

            if(nge.size()==i) nge.push_back(-1);
        }
        nge.push_back(-1);

        return nge;
       
    }
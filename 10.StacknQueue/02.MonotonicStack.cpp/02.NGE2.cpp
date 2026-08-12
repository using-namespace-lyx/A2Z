#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {

        int n=arr.size();
        vector<int> nge(n,-1);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<i+n;j++)
            {
                int index=j%n;

                if(arr[index]>arr[i])
                {
                    nge[i]=arr[index];
                    break;
                }
            }
        }

        return nge;
        
    }
};

//---------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {

        stack<int> s;
        int n=arr.size();
        vector<int> nge(n,-1);

        for(int i=2*n-1;i>=0;i--)
        {
            int j=i%n;

            while(!s.empty() && s.top()<=arr[j]) s.pop();

            if(!s.empty() && i<n && i>=0) nge[i]=s.top();

            s.push(arr[j]);
        }

        return nge;
        
    }
};
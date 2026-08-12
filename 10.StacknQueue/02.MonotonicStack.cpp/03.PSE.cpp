#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElements(const vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        stack<int> s;
        vector<int> pse(n,-1);

        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top()>=arr[i]) s.pop();

            if(!s.empty()) pse[i]=s.top();

            s.push(arr[i]);
        }

        return pse;

    }
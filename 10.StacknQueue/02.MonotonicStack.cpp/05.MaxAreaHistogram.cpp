#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> s;
        int n=heights.size();
        int nse,pse,element;
        int area=0;

        for(int i=0;i<n;i++)
        {
            while(!s.empty()&& heights[s.top()]>heights[i])
            {
                element=heights[s.top()];
                s.pop();
                nse=i;
                pse=s.empty()?-1:s.top();

                area=max(area,element*(nse-pse-1));
            }

            s.push(i);
        }

        while(!s.empty())
        {
            nse=n;
            element=heights[s.top()];
            s.pop();
            pse=s.empty()?-1:s.top();

            area=max(area,element*(nse-pse-1));
        }

        return area;
        
    }
};
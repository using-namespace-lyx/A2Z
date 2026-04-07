#include<bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &v)
{
    vector<int> res;
    int m=v.size(),n=v[0].size();
    int top=0,bottom=m-1,left=0,right=n-1;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
        res.push_back(v[top][i]);

        top++;

        for(int i=top;i<=bottom;i++)
        res.push_back(v[i][right]);
        right--;

        if(top<=bottom){
        for(int i=right;i>=left;i--)
            res.push_back(v[bottom][i]);
        bottom--;

        }

        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                res.push_back(v[i][left]);
            }

            left++;
        }
    }

    return res;
}
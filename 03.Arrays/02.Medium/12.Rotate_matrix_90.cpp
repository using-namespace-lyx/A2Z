#include<bits/stdc++.h>
using namespace std;

// brute

vector<vector<int>> rotate90(vector<vector<int>> &v)
{
    int m=v.size(),n=v[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0)); // ans is n*m instead of m*n

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[j][n-1-i]=v[i][j];
        }
    }

    return ans;
}


// roate in place

/*

Step 1: Take transpose in place
Step 2: Reverse eevry row

*/

void rotate90inplace(vector<vector<int>> &v)
{
    int m=v.size(),n=v[0].size();

    for(int i=0;i<m;i++)
{
    for(int j=i+1;j<n;j++)
    {
        swap(v[i][j],v[j][i]);
    }
}

    for(int i=0;i<m;i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
}
#include<bits/stdc++.h>
using namespace std;
/*
QUESTION:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

// brute

void setzeroes(vector<vector<int>> &v)
{
    int m=v.size(),n=v[0].size();

    vector<bool> rows(m,0),cols(n,0);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==0)
            {
                rows[i]=1;
                cols[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        
            for(int j=0;j<n;j++)
            {
                if(rows[i]==1 || cols[j]==1)
                v[i][j]=0;
            }
        
    }
}

// optimal

void setzeroes(vector<vector<int>> &v)
{
    bool colzero0=1;
    int m=v.size(),n=v[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==0)
            {
                v[i][0]=0;

                if(j!=0)
                {
                    v[0][j]=0;
                }
                else
                colzero0=0;

            }
        }
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(v[i][j]!=0){
            if(v[i][0]==0 || v[0][j]==0)
            v[i][j]=0;
            }
        }
    }

    if(v[0][0]==0)
    {
        for(int j=0;j<n;j++)
        v[0][j]=0;
    }

    if(colzero0==0)
    {
        for(int i=0;i<m;i++)
        v[i][0]=0;
    }
}

// TIME COMPLEXITY: O(m * n), where m and n are the dimensions of the matrix.
// SPACE COMPLEXITY: O(1), as we are using constant extra space.
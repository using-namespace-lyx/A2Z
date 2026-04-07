#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m=mat.size(),n=mat[0].size();

        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((j==0 || mat[i][j] > mat[i][j-1] ) && (j==(n-1) || mat[i][j]>mat[i][j+1]) && (i==0|| mat[i][j]>mat[i-1][j]) && (i==(m-1) || mat[i][j]> mat[i+1][j]) )
                return {i,j};
            }
        }
        
    }
};


class Solution {
public:
int pickMaxInColumn(vector<vector<int>> &mat, int col)
{
    int maxi=INT_MIN,index=-1;

    for(int i=0;i<mat.size();i++)
    {
        if(mat[i][col]>maxi)
        {
            maxi=mat[i][col];
            index=i;
        }
    }

    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=n-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int row=pickMaxInColumn(mat,mid);

            int left= mid>0? mat[row][mid-1]:-1;
            int right= mid<(n-1)? mat[row][mid+1]:-1;

            if(mat[row][mid]>left && mat[row][mid]>right)
            {
                return {row,mid};
            }
            else if(mat[row][mid]<left)
            high=mid-1;

            else
            low=mid+1;
        }

        return {-1,-1};
        
    }
};
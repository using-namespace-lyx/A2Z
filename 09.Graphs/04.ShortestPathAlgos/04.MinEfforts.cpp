#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> distance(m,vector<int>(n,1e9));
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > q;

        q.push({0,{0,0}});
        distance[0][0]=0;

        while(!q.empty())
        {
            auto top=q.top();
            q.pop();
            int dist=top.first,row=top.second.first,col=top.second.second;
            vector<int> delrow={-1,0,1,0},delcol={0,-1,0,1};

            for(int k=0;k<4;k++)
            {
                int nr=row+delrow[k],nc=col+delcol[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n)
                {
                    int newdist=max(dist,abs(heights[row][col]-heights[nr][nc]));
                    if(newdist<distance[nr][nc])
                    {
                    distance[nr][nc]=newdist;
                    q.push({newdist,{nr,nc}});
                    
                    }
                }
            }
        }

        return distance[m-1][n-1];

    }
};


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> distance(m,vector<int>(n,1e9));

        distance[source.first][source.second]=0;

        queue<pair<int,pair<int,int>>> q;

        q.push({0,{source.first,source.second}});

        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            int dist=top.first;
            int row=top.second.first,col=top.second.second;

            vector<int> delrow={-1,0,1,0},delcol={0,-1,0,1};

            for(int k=0;k<4;k++)
            {
                int nr=row+delrow[k],nc=col+delcol[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n)
                {
                    if(grid[nr][nc]==1 && (dist+1)<distance[nr][nc])
                    {
                        distance[nr][nc]=dist+1;
                        q.push({dist+1,{nr,nc}});

                    }
                }
            }

            
        }

        int res=distance[destination.first][destination.second];

        return res!=1e9?res:-1;


       
    }
};
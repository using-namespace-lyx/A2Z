
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        vector<int> count(n,0);
        int cnt=INT_MAX,res=0;
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }

        for(int i=0;i<n;i++)
        {
            vector<int> distance(n,1e9);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            distance[i]=0;
            pq.push({0,i});

            while(!pq.empty())
            {
                auto topr=pq.top();
                int dist=topr.first,node=topr.second;
                pq.pop();

                for(auto npr:adj[node])
                {
                    int cost=npr.second,neighbour=npr.first;
                    if(dist+cost<distance[neighbour])
                    {
                        distance[neighbour]=dist+cost;
                        pq.push({distance[neighbour],neighbour});
                    }
                }

            }

            for(int j=0;j<n;j++)
            {
                if(distance[j]<=distanceThreshold)
                {
                    count[i]++;
                }
            }

            if(count[i]<=cnt)
            {
                cnt=count[i];
                res=i;
            }
        }

        return res;
		
	}
};


class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {

            vector<vector<int>> matrix(n,vector<int>(n,1e9));

            for(auto edge:edges)
            {
                matrix[edge[0]][edge[1]]=edge[2];
                matrix[edge[1]][edge[0]]=edge[2];
                
            }
            /* for(int i=0;i<n;i++)
            {
               matrix[i][i]=0;            } */

            vector<int> count(n,0);

            for(int k=0;k<n;k++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                       

                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
            int res=0,cnt=INT_MAX;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && matrix[i][j]<=distanceThreshold) // i!=j needed if matrix[i][i]!=0
                    {
                        count[i]++;
                        
                    }

                    
                }

                if(count[i]<=cnt)
                    {
                        cnt=count[i];
                        res=i;
                    }
            }

            

            return res;
		
	}
};

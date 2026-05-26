#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        vector<int> distance(V,1e9);
        distance[S]=0;

        for(int i=0;i<V;i++)
        {

            for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int cost=edge[2];

                if(distance[u]!=1e9 && distance[u]+cost<distance[v])
                {
                    if(i==V-1) return {-1};
                    distance[v]=distance[u]+cost;
                }
            

        
            }

        }

        return distance;


    }
};

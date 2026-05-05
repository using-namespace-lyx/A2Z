#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countPaths(int n, vector<vector<int>> &roads) {

        vector<int> distance(n,INT_MAX);
        distance[0]=0;

        vector<int> ways(n,0);
        ways[0]=1;
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

        for(auto road:roads)
        {
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,0});

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node])
            {
                int neighbour = it.first;
                int cost = it.second;
                if(dist+cost<distance[neighbour])
                {
                    distance[neighbour]=dist+cost;
                    ways[neighbour]=ways[node];
                    pq.push({distance[neighbour],neighbour});
                }
                else if(dist+cost==distance[neighbour])
                {
                    ways[neighbour]+=ways[node];
                }
            }


        }

        return ways[n-1]%int((1e9+7));
      
    }
};
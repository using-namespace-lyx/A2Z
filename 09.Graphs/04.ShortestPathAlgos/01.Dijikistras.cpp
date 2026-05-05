#include<bits/stdc++.h>
using namespace std;

class  Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {

        vector<vector<pair<int,int>>> adj(V,vector<pair<int,int>>());

        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }

        vector<int> distance(V,1e9);
        distance[S]=0;

        // Priority queue should store {distance, node} to sort by distance
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, S});

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto neighbourpair:adj[node])
            {
                int neighbour = neighbourpair.first;
                int cost = neighbourpair.second;

                if(dist+cost<distance[neighbour])
                {
                    distance[neighbour]=dist+cost;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }

        return distance;

    }
};
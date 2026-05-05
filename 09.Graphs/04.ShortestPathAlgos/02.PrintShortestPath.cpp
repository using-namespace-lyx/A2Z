#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto edge:edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> distance(n+1, 1e9);
        vector<int> parent(n+1, -1);

        distance[1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 1}); // (distance, node)

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // if (dist > distance[node]) continue;

            for(auto it : adj[node]) {
                int neighbour = it.first;
                int cost = it.second;
                if(dist + cost < distance[neighbour]) {
                    distance[neighbour] = dist + cost;
                    parent[neighbour] = node;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }

        if(distance[n] == 1e9) return {-1};

        vector<int> path;
        int curr = n;

        while(curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());
        path.insert(path.begin(), distance[n]);

        return path;
    }
};
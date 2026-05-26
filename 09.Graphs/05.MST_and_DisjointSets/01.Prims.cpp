#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,-1}});
        vector<int> visited(V,0);
        vector<pair<int,int>> MST;
        int wt=0;

        while(!pq.empty())
        {
            auto toppair=pq.top();
            pq.pop();
            int weight=toppair.first,node=toppair.second.first, parent=toppair.second.second;
            if(visited[node]) continue;
            visited[node]=1;

            if(weight!=0) wt+=weight;

            if(parent!=-1) MST.push_back({parent,node});

            for( auto edge:adj[node])
            {
                int neighbour=edge[0],cost=edge[1];

                if(!visited[neighbour])
                {
                    pq.push({cost,{neighbour,node}});
                }
            }

        }

        return wt;
       
    }
};

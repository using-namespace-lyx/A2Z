#include <bits/stdc++.h>


using namespace std;
class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K) {

            vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

            for(auto flight:flights)
            {
                adj[flight[0]].push_back({flight[1],flight[2]});
            }

            vector<int> distance(n,1e9);
            distance[src]=0;

            

            priority_queue<pair<int,pair<int,int>>  ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;

            pq.push({0,{0,src}});

            while(!pq.empty())
            {
               int stops = pq.top().first;
               pair<int,int> nodepair = pq.top().second;
               pq.pop();
               int node=nodepair.second;
               int dist=nodepair.first;

               for(auto it : adj[node])
               {
                int neighbour = it.first;
                int cost = it.second;
                if(stops<=(K) && dist+cost<distance[neighbour] )
                {
                    distance[neighbour]=dist+cost;
                    
                    pq.push({stops+1,{distance[neighbour],neighbour}});
                }
               } 
            }

            int res=distance[dst];

            return res!=1e9?res:-1;
        
    }
};

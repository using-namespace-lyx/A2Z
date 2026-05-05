#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end) {

        if(start==end) return 0;

        vector<int> distance(1e5,1e9);
        distance[start]=0;

        queue<pair<int,int>> pq;

        pq.push({0,start});

        while(!pq.empty())
        {
            int dist = pq.front().first;
            int node = pq.front().second;
            pq.pop();

            for(int element:arr)
            {
                int prod=(node*element)%int(1e5);

                if(prod==end) return dist+1;

                if(dist+1<distance[prod])
                {
                    distance[prod]=dist+1;
                    pq.push({dist+1,prod});
                }
            }
        }

        

        return -1;
   
    }
};

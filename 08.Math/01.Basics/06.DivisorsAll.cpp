#include<bits/stdc++.h>
using namespace std;

// TC: O(sqrt N)
vector<int> divisorsAll(int n)
{
    vector<int> res;

    for(int i=0;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(n/i !=i)
            {
                res.push_back(n/i);

            }
        }


    }
    sort(res.begin(),res.end());
    return res;
}
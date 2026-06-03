#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> getSieve(int n)
        {
            // optimal
            vector<int> seive(n+1,1);
            seive[0]=0;
            seive[1]=0;

            for(int i=2;i*i<=n;i++)
            {
                if(seive[i])
                {
                    for(int j=i*i;j<=n;j+=i)
                    {
                        seive[j]=0;
                    }
                }
            }

            for(int i=2;i<=n;i++)
            {
                seive[i]+=seive[i-1];
            }

            return seive;
        }
        vector<int> primesInRange(vector<vector<int>>& queries){

            int q=queries.size();
            vector<int> res;
            vector<int> seive=getSieve((int)10e6);
            for(int i=0;i<q;i++)
            {
                int l=queries[i][0], r=queries[i][1];
                int count=seive[r]-seive[l-1];

                res.push_back(count);


            }

            return res;
            //your code goes here
        }
};

class Solution1{
    public:
        bool isPrime(int n)
        {
            if(n<=1) return false;
            for(int i=2;i*i<=n;i++)
            {
                if(n%i==0) return false;
            }

            return true;
        }
        vector<int> primesInRange(vector<vector<int>>& queries){

            int q=queries.size();
            vector<int> res;
            for(int i=0;i<q;i++)
            {
                int l=queries[i][0], r=queries[i][1];
                int count=0;

                for(int j=l;j<=r;j++)
                {
                    if(isPrime(j))
                    {
                        count++;

                    }
                }

                res.push_back(count);


            }

            return res;
            //your code goes here
        }
};

class Solution2{
    public:
        vector<int> getSieve(int n)
        {
            vector<int> seive(n+1,1);
            seive[0]=0;
            seive[1]=0;

            for(int i=2;i*i<=n;i++)
            {
                if(seive[i])
                {
                    for(int j=i*i;j<=n;j+=i)
                    {
                        seive[j]=0;
                    }
                }
            }

            return seive;
        }
        vector<int> primesInRange(vector<vector<int>>& queries){

            int q=queries.size();
            vector<int> res;
            vector<int> seive=getSieve((int)10e6);
            for(int i=0;i<q;i++)
            {
                int l=queries[i][0], r=queries[i][1];
                int count=0;

                for(int j=l;j<=r;j++)
                {
                    if(seive[j])
                    {
                        count++;

                    }
                }

                res.push_back(count);


            }

            return res;
            //your code goes here
        }
};


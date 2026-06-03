#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        vector<vector<int>> primeFactors(vector<int>& queries){
            //your code goes here

            vector<int> spf(int(10e6));

            for(int i=0;i<=int(10e6);i++)
            spf[i]=i;

            for(int i=2;i*i<=int(10e6);i++)
            {
                if(spf[i]==i)
                {
                    for(int j=i*i ; j<=int(10e6);j+=i)
                    {
                        if(spf[j]==j)
                        {
                            spf[j]=i;
                        }
                    }
                }
            }

            vector<vector<int>> res;

            for(int num:queries)
            {
                vector<int> temp;
                while(num!=1)
                {
                    temp.push_back(spf[num]);
                    num/=spf[num];

                }

                res.push_back(temp);
            }

            return res;
        }
};


class Solution{
    public:
        vector<int> getPrimeFactors(int n)
        {
            vector<int> res;
            for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    while(n%i==0)
                    {
                        n/=i;
                        res.push_back(i);
                    }
                }
            }

            if(n!=1) res.push_back(n);

            return res;
        }
        vector<vector<int>> primeFactors(vector<int>& queries){
            //your code goes here

            int q=queries.size();

            vector<vector<int>> res;

            for(int i=0;i<q;i++)
            {
                res.push_back(getPrimeFactors(queries[i]));
            }

            return res;
        }
};
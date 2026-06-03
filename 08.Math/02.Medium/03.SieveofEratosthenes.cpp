#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<int> res;
    vector<bool> isPrime(n+1,1);

    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i])
        {
            

            for(int j=i*i;j<=n;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        res.push_back(i);
    }

    // O( N * log(log N)) + O(N)

    return res;

}
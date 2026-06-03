#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }

    return true;
}
vector<int> sol1(int n)
{

    // O(sqrt(n)) *2*O(sqrt(N)) =2O(N)
    vector<int> res;
    for(int i=0;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(isPrime(i))
            {
                res.push_back(i);
            }

            if(n/i!=i)
            {
                if(isPrime(n/i))
                {
                    res.push_back(n/i);
                }
            }
        }
    }

    return res;
}


vector<int> soln2(int n)
{
    vector<int> res;

    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);

            while(n%i==0)
            {
                n=n/i;
            }
        }
    }

    // For composit numbers somewhere O(logN)(for internal divisions) + O(k number of outer loop turns), for primes O(N)
}


vector<int> soln3(int n)
{
    vector<int> res;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);

            while(n%i==0)
            {
                n=n/i;
            }
        }
    }

    if(n!=1) res.push_back(n);

    return res;

    //O(srt(N) * logN)
}
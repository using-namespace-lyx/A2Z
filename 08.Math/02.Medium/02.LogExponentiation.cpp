#include<bits/stdc++.h>
using namespace std;

double power(double x, int n)
{
    double ans=1;

    while(n>0)
    {
        if(n%2==1)
        {
            ans*=x;
            n=n-1;
        }

        else
        {
            x=x*x;
            n/=2;
        }
    }

    if(n<0) return 1/ans;

    return ans;

}
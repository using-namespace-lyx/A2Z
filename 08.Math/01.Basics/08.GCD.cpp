#include<bits/stdc++.h>
using namespace std;

int GCD(int n1,int n2) {

        if(n2>n1) return GCD(n2,n1);

        if(n2==0) return n1;

        return GCD(n2,n1%n2);
        
    }

int GCD(int n1,int n2)
{
    while(!(n1==0 || n2==0))
    {
        if(n1>n2)
        {
            n1=n1%n2;
        }

        else
        {
            n2=n2%n1;
        }


    }

    if(n1==0) return n2;

    return n1;
}

int GCD(int n1,int n2) {

        if(n2>n1) return GCD(n2,n1);

        if(n2==0) return n1;

        return GCD(n1%n2,n2);
        
    }
#include<bits/stdc++.h>
using namespace std;

int count(int n)
{
    int count=0;
    while(n>0)
    {
        n/=10;
        count++;
    }

    return count;
}

int count2(int n)
{
    return (int)log10(n)+1;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {

        int arm=0,dup1=n,dup2=n,count=0;
        while(dup1>0)
        {
            
            dup1/=10;
            count++;
        }

        while(n>0)
        {
            int dig=n%10;
            n/=10;
            arm+=pow(dig,count);
        }
        if(dup2==arm) return true;

        return false;

    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution{	
public:		
    string largeOddNum(string& s){
        //your code goes here

        int i=0,n=s.size();
        while(i<n && s[i]=='0')
        {
            i++;

        }

        int start=i;

        i=n-1;

        while(i>=0 && ((s[i]-'0')%2)==0) i--;

        if(i<0) return "";

        int end=i;

        return s.substr(start,end-start+1);
        
    }
};
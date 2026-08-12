#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
		bool rotateString(string& s,string& goal){
			//your code goes here
            int n= s.size();
            for(int i=0;i<n;i++)
            {
                s=s.substr(1,n-1)+s[0];
                if(s==goal) return true;
            }

            return false;
		}
};
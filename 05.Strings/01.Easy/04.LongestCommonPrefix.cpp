#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
		string longestCommonPrefix(vector<string>& str){
			//your code goes here
            sort(str.begin(),str.end());
            int n=str.size();
            string s1=str[0],s2=str[n-1];

            int i=0;
            while(s1[i]==s2[i]) i++;

            int end=i-1; if(end<0) return "";

            return s1.substr(0,end+1);
		}
};
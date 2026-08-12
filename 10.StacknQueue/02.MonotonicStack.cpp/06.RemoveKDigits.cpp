#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<int> s;

        for(char ch:num)
        {
            while(!s.empty() && k>0 && s.top()>ch)
            {
                s.pop();
                k--;
            }

            s.push(ch);

        }

        while(k>0) 
        {
            s.pop();
            k--;
        }

        string res="";

        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }

        while(!res.empty() && res.back()=='0')
        {
            res.pop_back();
        }

        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
        return res;

        
  
    }
};
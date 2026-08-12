#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        vector<string> list;
        string temp="";
        for(char c:s)
        {
            if(c!=' ')
                temp.push_back(c);
            else
            {
                if(temp!="")
                {
                    list.push_back(temp);
                    temp="";
                }
            }

        }
        if(temp != "")
        list.push_back(temp);

        string finall="";

        for(int i=(int)list.size()-1;i>=0;i--)
        {
            finall+=list[i];
            if(i!=0)
            finall+=' ';
        }
       
       return finall;
    } 
};


class Solution {
public:
    string reverseWords(string s) {

        int n=s.size();
        string res;
        
        int i=n-1;

        while(i>=0)
        {
            while(i>=0 && s[i]==' ') i--; // get rid of trialing spaces

            int end=i;

            if(end<0) break;

            while(i>=0 && s[i]!=' ') i--;

            int start=i+1;
            if(start<0) break;

            res+=(s.substr(start,end-start+1));

            res+=' ';


        }
        if(!res.empty())
            res.pop_back();

        return res;
       
    } 
};
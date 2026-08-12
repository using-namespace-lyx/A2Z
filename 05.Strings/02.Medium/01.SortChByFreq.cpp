#include<bits/stdc++.h>
using namespace std;

class Solution{	
	public:
        static bool cmp(pair<int,char> p1, pair<int,char>p2)
        {
            if(p1.first>p2.first) return true;

            if(p1.first<p2.first) return false;

            if(p1.second<p2.second) return true;

            return false;
        }
		vector<char> frequencySort(string& s){
			//your code goes here
            pair<int,char> freq[26];
            vector<char> res;

            for(int i=0;i<26;i++)
            freq[i]={0,i+'a'};

            for(char ch:s)
            (freq[ch-'a'].first)++;

            sort(freq,freq+26,cmp);

            for(auto p:freq)
            {
                if(p.first==0) break;

                res.push_back(p.second);

            }

            return res;


		}
};
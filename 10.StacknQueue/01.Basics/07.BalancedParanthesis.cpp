#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string str) {

        unordered_map<char,char> mpp={{'(',')'},{'{','}'},{'[',']'}};
        stack<char> st;

        for(char ch:str)
        {
            if(mpp.find(ch)!=mpp.end())
            {
                st.push(ch);

            }
            else
            {
                if(st.empty()) return false;

                char comp=st.top();

                if(ch!=mpp[comp]) return false;

                st.pop();
            }
        }

        return st.empty();


       
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c:s)
        {
            
            if(c=='('||c=='{'||c=='[')
            {
                st.push(c);
            }
            else if(c==')' && (st.empty() || st.top()=='['|| st.top()=='{'))
            {
                return false;
            }
            else if(c=='}' && (st.empty() || st.top()=='['|| st.top()=='('))
            {
                return false;
            }
            else if(c==']' && (st.empty() || st.top()=='{'|| st.top()=='('))
            {
                return false;
            }
            else{
            st.pop();
            }

        }

        return st.empty()?true:false;
        
    }
};

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s)
        {
            if(c == '(')
                st.push(')');
            else if(c == '{')
                st.push('}');
            else if(c == '[')
                st.push(']');
            else
            {
                if(st.empty() || st.top() != c)
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a[256] = {0}; // 256 for all ASCII, 26 for a to z
        int b[256] = {0};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (a[s[i]] != b[t[i]]) return false;
            a[s[i]] = i + 1;
            b[t[i]] = i + 1;
        }
        return true;

        // unordered_map <char, char> s2t, t2s;
        // for (int i = 0; i < s.size(); ++i) {
        //     if (s2t[s[i]]) {
        //         if (!t2s[t[i]] || s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) return false;
        //     } else {
        //         if (t2s[t[i]]) return false;
        //         s2t[s[i]] = t[i];
        //         t2s[t[i]] = s[i];
        //     }
        // }
        // return true;
        
        // Time Complexity: O(N)
        // Space Complexity: O(K), max 26 chars as per constraints
    }
};
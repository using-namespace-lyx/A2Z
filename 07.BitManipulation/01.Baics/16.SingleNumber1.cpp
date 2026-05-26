#include <bits/stdc++.h>
using namespace std;
    
int getSingleElement(vector<int>& arr) {
    int n = arr.size();

    // Loop through every element
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // current element to check
        int cnt = 0;

        // Count occurrences of this element
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // If it occurs only once, return it
        if (cnt == 1) return num;
    }

    // This line should never be reached
    return -1;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the single non-repeating element using XOR
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();
        int xorr = 0;

        // XOR all elements. Duplicates cancel out, leaving the single element.
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ arr[i];
        }

        return xorr;
    }
};

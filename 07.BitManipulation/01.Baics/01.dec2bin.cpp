#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// TC: O(log N)
// SC: O(log N) to store the result string
string dec2bin(int dec) {
    if (dec == 0) return "0"; // Handle edge case
    
    string st = "";
    while (dec > 0) {
        // dec & 1 is faster than dec % 2
        st.push_back((dec & 1) ? '1' : '0'); 
        // dec >>= 1 is faster than dec /= 2
        dec >>= 1; 
    }

    reverse(st.begin(), st.end());
    return st;
}

int main() {
    cout << dec2bin(12); // Output: 1100
}
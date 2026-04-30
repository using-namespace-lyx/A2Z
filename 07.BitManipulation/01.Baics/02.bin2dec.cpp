#include <iostream>
#include <string>

using namespace std;

// TC:O(N)
// SC : O(1)


int bin2dec(const string& s) {
    int res = 0;
    for (char c : s) {
        // Shift left by 1 (multiply by 2) and add the current bit
        // like res=res*2+bit similar to num =num*10+dig
        res = (res << 1) | (c - '0');
    }
    return res;

}

int main() {
    
    cout << bin2dec("1010"); // Output: 10
    cout << endl;
    return 0;
}
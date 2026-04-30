#include <iostream>
#include <cmath>

using namespace std;

/*
QUESTION:
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two if there exists an integer x such that n == 2^x.
*/

/*
APPROACH 1: Bit Manipulation (Most Optimal)
A property of powers of two in binary is that they have exactly one set bit (e.g., 8 is 1000).
If we subtract 1 from a power of two, all bits to the right of the set bit become 1, and the set bit itself becomes 0 (e.g., 7 is 0111).
Therefore, `n & (n-1)` will always be 0 for a power of two.

TC: O(1)
SC: O(1)
*/
bool isPowerOfTwoBitwise(int n) {
    // n must be positive to be a power of two
    return n > 0 && (n & (n - 1)) == 0;
}

/*
APPROACH 2: Using Built-in Function (Popcount)
Since a power of two has exactly one set bit, we can count the number of set bits.
In C++, `__builtin_popcount(n)` returns the number of set bits.

TC: O(1) (Usually maps to a single CPU instruction like POPCNT)
SC: O(1)
*/
bool isPowerOfTwoPopcount(int n) {
    return n > 0 && __builtin_popcount(n) == 1;
}

/*
APPROACH 3: Iterative Division
We can repeatedly divide the number by 2 as long as it's even. 
If the final result is 1, the original number was a power of two.

TC: O(log N)
SC: O(1)
*/
bool isPowerOfTwoIterative(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

/*
APPROACH 4: The Modulo Trick (Math-based)
For a 32-bit signed integer, the largest power of two is 2^30 = 1073741824.
Any power of two 'n' will perfectly divide this largest power of two.

TC: O(1)
SC: O(1)
*/
bool isPowerOfTwoModulo(int n) {
    return n > 0 && (1073741824 % n == 0);
}

int main() {
    int testCases[] = {1, 16, 18, 0, -8};
    
    for(int n : testCases) {
        cout << "n = " << n << ": " << (isPowerOfTwoBitwise(n) ? "True" : "False") << endl;
    }
    
    /*
    Example Output:
    n = 1: True
    n = 16: True
    n = 18: False
    n = 0: False
    n = -8: False
    */
    return 0;
}
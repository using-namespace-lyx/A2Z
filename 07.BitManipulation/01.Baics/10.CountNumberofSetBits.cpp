#include <iostream>

using namespace std;

/*
QUESTION:
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
*/

/*
APPROACH 1: Simple Iteration (Naive)
We check each bit one by one by using the right shift operator.

TC: O(Number of bits) - In C++, for an int, this is O(32).
SC: O(1)
*/
int countSetBitsNaive(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

/*
APPROACH 2: Brian Kernighan’s Algorithm (Optimal for sparse bits)
This approach uses the property `n & (n - 1)` which clears the last set bit.
Instead of iterating through all bits, we only iterate as many times as there are set bits.

TC: O(Number of set bits)
SC: O(1)
*/
int countSetBitsOptimal(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // Clears the last set bit
        count++;
    }
    return count;
}

/*
APPROACH 3: Built-in Function
Modern compilers (GCC/Clang) provide a built-in function that often maps directly 
to a CPU instruction (POPCNT).

TC: O(1) 
SC: O(1)
*/
int countSetBitsBuiltin(int n) {
    return __builtin_popcount(n);
}

/*
APPROACH 4: Look-up Table (Precomputation)
For scenarios where you need to count bits for millions of numbers, we can 
precompute the bit counts for every possible byte (0-255) and sum them up.

TC: O(1) (After precomputation, it takes 4 lookups for a 32-bit int)
SC: O(1) (Constant space for the table)
*/
int table[256];
void precompute() {
    table[0] = 0;
    for (int i = 1; i < 256; i++) {
        table[i] = (i & 1) + table[i / 2];
    }
}

int countSetBitsTable(int n) {
    // For a 32-bit integer, check byte by byte
    return table[n & 0xff] + 
           table[(n >> 8) & 0xff] + 
           table[(n >> 16) & 0xff] + 
           table[(n >> 24) & 0xff];
}

int main() {
    int n = 13; // Binary: 1101
    precompute();
    cout << "Set bits in " << n << " is: " << countSetBitsOptimal(n) << endl; // Output: 3
    return 0;
}
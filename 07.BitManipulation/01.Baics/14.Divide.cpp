#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int divide(int n, int d) {
    if (n == INT_MIN && d == -1) return INT_MAX;
    
    // Determine sign
    bool negative = (n < 0) ^ (d < 0);
    
    // FIX 1: Cast to long long before abs() to prevent overflow
    long long dividend = abs((long long)n);
    long long divisor = abs((long long)d);
    
    // FIX 2: Use long long for quotient to handle the overflow case
    long long quotient = 0;
    
    while (dividend >= divisor) {
        int count = 0;
        // Find largest count such that divisor * 2^count <= dividend
        while (dividend >= (divisor << (count + 1))) {
            count++;
        }
        
        quotient += (1LL << count); // Use 1LL to ensure shift is 64-bit
        dividend -= (divisor << count);
    }
    
    // Final check for return limits
    if (negative) {
        if (quotient > (long long)INT_MAX + 1) return INT_MIN; // Handling edge cases
        return (int)-quotient;
    }
    
    if (quotient > INT_MAX) return INT_MAX;
    return (int)quotient;
}
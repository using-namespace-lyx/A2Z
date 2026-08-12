
#include <iostream>
#include <algorithm>

using namespace std;

int findGcd(int n1, int n2) {
    // Iterate from the minimum of
    // n1 and n2 down to 1
    // Start from the minimum of n1 and n2
    // because the GCD cannot
    // exceed the smaller number
    
    for(int i = min(n1, n2); i > 0; i--) {
        // Check if i is a common
        // factor of both n1 and n2
        if(n1 % i == 0 && n2 % i == 0) {
            // If i is a common factor,
            // return it as the GCD
            return i;
        }
    }
    // If no common factors are found,
    // return 1 (as 1 is always a
    // divisor of any number)
    return 1;
}

int gcd(int a,int b)
{
    // log (min(a,b)) to base phiwhere phi is golden ratio worst case in terms of fibonacci neighbours
    while(a>0 && b>0)
    {
        if(a>b) a=a%b;
        else b=b%a;
    }

    if(a==0) return b;
    if(b==0) return a;
    return 1;
}
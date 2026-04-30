/*

so if n= 1010001000
n-1 would be 1010000111

basically last set bit becomes 0 and bits to right become 1

ex: 16 10000
15: 0 1111

thats the subtraction of 1 dude borrow,borrow,borrow till u get last set bit

*/

int removeLastSetBit(int n)
{
    return n & n-1;
}

/*
ex:  n =  1001001000
    n-1 = 1001000111

    so the last set bit would become 0 in n-1 & would result in 1001000000

*/
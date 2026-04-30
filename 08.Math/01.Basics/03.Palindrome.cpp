class Solution {
public:
    bool isPalindrome(int n) {

    int n1=n,res=0;
    while(n1>0)
    {
        int dig=n1%10;
        n1/=10;
        res=res*10+dig;

    }

    return res==n;

    }
};
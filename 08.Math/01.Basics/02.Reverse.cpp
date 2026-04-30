class Solution {
public:
    int reverseNumber(int n) {
        int res=0;
        while(n>0)
        {
            int dig=n%10;
            n/=10;
            res=res*10+dig;
        }

        return res;

    }
};
bool checksit(int n, int i)
{
    // check whether ith bit is set assume i is from 0;
    return n>>i &1;
    // return n &(1<<i) also works

    // if i starts with 1 replace i with i-1

}
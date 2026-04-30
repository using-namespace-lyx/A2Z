// An array has all 3numbers but exactly one number that appears once find it
// ex: [1 4 5 5 1 5 1] ans is 4
#include<bits/stdc++.h>
using namespace std;
int solution1(vector<int> arr)
{
    int ans=0;
    for(int index=0;index<31;index++)
    {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] & (1<<index))
            count++;
        }

        if(count%3 !=0)
        {
            ans |= (1<<index);
        }
    }

    return ans;

}

int solution2(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i+=3)
    {
        if(arr[i!=arr[i-1]])
        return arr[i-1];
    }

    return arr[arr.size()-1];
}
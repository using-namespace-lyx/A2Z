#include<bits/stdc++.h>
using namespace std;

vector<int> inter(vector<int> arr1, vector<int> arr2)
{
    int n1=arr1.size(),n2=arr2.size();

    vector<int> visited(n2,0),res;

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(arr2[j]==arr1[i] && !visited[j])
            {
                res.push_back(arr1[i]);
                visited[j]=1;
                break;
            }

            if(arr2[j]>arr1[i]) break;
        }
    }

    return res;
}

vector<int> intersection(vector<int> arr1, vector<int> arr2)
{
    int n1=arr1.size(),n2=arr2.size(),i=0,j=0;
    vector<int> res;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
        else
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return res;
}
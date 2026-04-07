// brute force using extra array

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int> &b)
{
    int m=a.size(),n=b.size();
    int i=0,j=0,k=0;
    vector<int> c(m+n,0);

    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }

    while(i<m)
    c[k++]=a[i++];

    while(j<n)
    c[k++]=b[j++];

    for(int i=0;i<m+n;i++)
    {
        if(i<m) a[i]=c[i];
        else b[i-m]=c[i];
    }
}

// TC: O(2*(m+n))
// SC: O(m+n)


void merge(vector<int> &a, vector<int> &b)
{
    int m=a.size(),n=b.size();
    int left=m-1,right=0;

    while(left>=0 && right<n)
    {
        if(a[left]>b[right])
        {
            swap(a[left],b[right]);
            left--;right++;
        }

        else
        {
            break;
        }
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

}

// TC: O(min(n,m))+O(mlogm + n logn)
// SC :O(1)

// gap method - shell sort
void swapgreater(vector<int> &a, vector<int> &b , int ind1, int ind2)
{
    if(a[ind1]>b[ind2])
    {
        swap(a[ind1],b[ind2]);
    }
}
void mergegap(vector<int> &a, vector<int> &b)
{
    int m=a.size(),n=b.size(), len=m+n, gap=(len/2)+(len%2);

    while(gap>0)
{
    int left=0,right=left+gap;

    while(right<len)
    {
        if(left<m && right>=m)
        {
            swapgreater(a,b,left,right-m);

        }

        else if(left>=m)
        {
            swapgreater(b,b,left-m,right-m);

        }
        else{
            swapgreater(a,a,left,right);

        }

        left++;right++;

    }

    if(gap=1) break;
    gap=gap/2+gap%2;

    
}


}

// TC: O(log(m+n))*O(m+n) // SC=O(1)
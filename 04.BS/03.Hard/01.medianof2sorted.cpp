#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// o(m+n) tc and sc
    double median(vector<int> &arr1, vector<int> &arr2) {
        int m=arr1.size();
        int n=arr2.size();

        int tot=m+n;
        vector<int> newy(tot,0);

        int i=0,j=0,k=0;
        while(i<m && j<n)
        {
            if(arr1[i]<arr2[j])
            newy[k++]=arr1[i++];

            else
            newy[k++]=arr2[j++];

        }

        while(i<m)
        newy[k++]=arr1[i++];

        while(j<n)
        newy[k++] =arr2[j++];

        if(tot%2==1) return newy[tot/2];

        else return ((newy[tot/2]+newy[tot/2-1])/2.0);


     

    }
};

double median(vector<int> &arr1, vector<int> &arr2)
{
    int m=arr1.size(), n=arr2.size();
    int tot=m+n;
    int c1= tot/2 -1;
    int c2=tot/2;
    int el1=0,el2=0;
    int count=0;

    int j=0,i=0;

    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            if(c1==count)
            {
                el1=arr1[i];
            }
            else if(c2==count)
            {
                el2=arr1[i];
            }
            count++;
            i++;
        }
        else
        {
            if(c1==count)
            {
                el1=arr2[j];
            }
            else if(c2==count)
            {
                el2=arr2[j];
            }
            count++;
            j++;

        }
    }

    while(i<m)
    {
        if(c1==count)
            {
                el1=arr1[i];
            }
            else if(c2==count)
            {
                el2=arr1[i];
            }
            count++;
            i++;
    }

    while(j<n)
    {
        if(c1==count)
            {
                el1=arr2[j];
            }
            else if(c2==count)
            {
                el2=arr2[j];
            }
            count++;
            j++;
    }

    if(tot%2) return el2;
    else return (el1+el2)/2.0;
}
 double median(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();

        // Ensure a is smaller array for optimization
        if (m > n) {
            // Swap a and b
            return median(b, a); 
        }
        
        // Length of the left half
        int left = (m+n+1)/2; 

        // Apply binary search
        int low = 0, high = m;
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            // Initialize l1, l2, r1, r2
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

            // Check if we have found the answer
            if (l1 <= r2 && l2 <= r1) {
                return (m+n)%2? max(l1,l2):(max(l1,l2)+min(r1,r2))/2;
            } 
            else if (l1 > r2) {
                // Eliminate the right half
                high = mid1 - 1;
            } 
            else {
                // Eliminate the left half
                low = mid1 + 1;
            }
        }
        
         // Dummy return statement 
        return -1;
    }

#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        // Create a set to store unique elements
        set<int> st;

        // Insert elements from first array
        for (int i = 0; i < n; i++) {
            st.insert(arr1[i]);
        }

        // Insert elements from second array
        for (int i = 0; i < m; i++) {
            st.insert(arr2[i]);
        }

        // Convert set to vector
        vector<int> unionArr(st.begin(), st.end());
        return unionArr;
    }

vector<int> Union(vector<int> arr1, vector<int> arr2)
{
    int n1=arr1.size(),n2=arr2.size();
    int i=0,j=0;
    vector<int> unionArr;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            if(unionArr.back()!=arr1[i] || unionArr.empty() )
            {
                unionArr.push_back(arr1[i]);
                i++;
            }
        }

        else if(arr1[i]>arr2[j])
        {
            if(unionArr.back()!=arr2[j] || unionArr.empty() )
            {
                unionArr.push_back(arr2[j]);
                j++;
            }
        }

        else
        {
            if(unionArr.back()!=arr2[j] || unionArr.empty() )
            {
                unionArr.push_back(arr2[j]);
                j++;
                i++;
            }

        }
    }

    while (i < n1) {
            if (unionArr.empty() || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
        }

        // Append remaining elements from arr2
        while (j < n2) {
            if (unionArr.empty() || unionArr.back() != arr2[j])
                unionArr.push_back(arr2[j]);
            j++;
        }

        return unionArr;


}
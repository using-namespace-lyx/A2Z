#include<bits/stdc++.h>
using namespace std;

/*

SELECTION SORT
────────────────────────────────

Idea:
Find minimum → put at front

Pattern:
sorted prefix | unsorted suffix

Outer loop:
i = 0 → n-2

Inner loop:
j = i+1 → n-1

Variable:
minIndex

Comparison:
arr[j] < arr[minIndex]

Swap:
arr[i] ↔ arr[minIndex]

Time:
Best    O(n²)
Average O(n²)
Worst   O(n²)

Comparisons:
n(n-1)/2

Swaps:
≤ n-1

Space:
O(1)

In-place:
YES

Stable:
NO (standard version)

Adaptive: ( adaptive algo is an algo that performs better when input is sorted or nearly sorted)
NO

Comparison-based:
YES

Main advantage:
Very few swaps

Main disadvantage:
O(n²) comparisons

*/

class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {

        int n=nums.size();

        for(int i=0;i<n-1;i++)
        {
            int minIndex=i;

            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<nums[minIndex])
                {
                    
                    minIndex=j;
                }
            }

            if(minIndex!=i)
            swap(nums[i],nums[minIndex]);
        }

        return nums;

    }
};

/*
Stable variant 
The stable variant is still O(n²) time, but unlike the standard version, it can perform O(n²) element movements/shifts.

So:

	Standard	Stable variant
Comparisons	O(n²)	O(n²)
Swaps	O(n)	—
Shifts/movements	O(n)	O(n²)
Space	O(1)	O(1)
Stable	❌	✅

*/

void stableSelectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find minimum in unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Shift elements right instead of swapping
        int minValue = arr[minIndex];

        for (int j = minIndex; j > i; j--) {
            arr[j] = arr[j - 1];
        }

        arr[i] = minValue;
    }
}
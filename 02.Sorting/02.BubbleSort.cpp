#include<bits/stdc++.h>
using namespace std;

/*
BUBBLE SORT
────────────────────────────

Core idea:
Compare adjacent elements
and swap if out of order.

After each pass:
Largest remaining element
moves to the end.

Standard:
O(n²) best/average/worst

Optimized with swapped:
Best    O(n)
Average O(n²)
Worst   O(n²)

Space:
O(1)

In-place:
YES

Stable:
YES

can be unstable if u replace < with <=

Adaptive:
YES (with early termination)

Worst swaps:
O(n²)

Worst comparisons:
n(n-1)/2

Key optimization:
bool swapped

Ascending condition:
arr[j] > arr[j+1]

Descending:
arr[j] < arr[j+1]

Main advantage:
Simple + stable + adaptive

Main disadvantage:
O(n²), many swaps
*/

class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {

        int n=nums.size();
        

        for(int i=0;i<n-1;i++)
        {
            bool swapped=false;
            
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j+1]<nums[j])
                {
                    swap(nums[j],nums[j+1]);
                    swapped=true;

                }
                
            }

            if(!swapped)
            break;
        }

        return nums;

    }
};

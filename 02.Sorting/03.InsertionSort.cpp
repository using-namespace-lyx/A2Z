#include<bits/stdc++.h>
using namespace std;
/*
INSERTION SORT
────────────────────────────

Core idea:
Take next element and
insert into sorted prefix.

Initial:
First element is sorted.

Outer loop:
i = 1 → n-1

key:
arr[i]

j:
i - 1

Shift while:
arr[j] > key

Insert at:
arr[j + 1]

Best:
O(n)

Average:
O(n²)

Worst:
O(n²)

Space:
O(1)

In-place:
YES

Stable:
YES // can be made unstable with = sign

Adaptive:
YES

Worst shifts:
O(n²)

Best shifts:
O(1)

Excellent for:
Nearly sorted data
Small arrays

Deep connection:
Shifts ≈ number of inversions

Binary insertion:
Fewer comparisons,
but still O(n²) overall
because of shifting.
*/
class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {

        int n=nums.size();

        for(int i=1;i<n;i++)
        {
            int el=nums[i];

            int j=i-1;

            while (j >= 0 && nums[j] > el)
            {
                nums[j + 1] = nums[j];
                j--;
            }

            nums[j + 1] = el;
        }

        return nums;
    }
};

// with sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int j = i;

        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
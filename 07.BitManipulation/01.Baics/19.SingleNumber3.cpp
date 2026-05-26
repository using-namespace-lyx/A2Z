#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the single 
    number in the given array */
    vector<int> singleNumber(vector<int>& nums){
        
        // Array to store the answer
        vector<int> ans;
        
        /* Map to store the elements 
        and their frequencies */
        unordered_map <int, int> mpp;
        
        // Iterate on the array
        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++; // Update the map
        }
        
        // Iterate on the map
        for(auto it : mpp) {
            // If frequency is 1
            if(it.second == 1) {
                /* Add the element to
                the result array */
                ans.push_back(it.first);
            }
        }   
        
        // Return the result after sorting
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    /* Function to get the single 
    numbers in the given array */
    vector<int> singleNumber(vector<int>& nums){
        // Variable to store size of array
        int n = nums.size();
        
        // Variable to store XOR of all elements
        long XOR = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            // Update the XOR
            XOR = XOR ^ nums[i];
        }
        
        /* Variable to get the rightmost 
        set bit in overall XOR */
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        
        /* Variables to stores XOR of
        elements in bucket 1 and 2 */
        int XOR1 = 0, XOR2 = 0;
        
        // Traverse the array
        for(int i=0; i < n; i++) {
            
            /* Divide the numbers among bucket 1
             and 2 based on rightmost set bit */
            if(nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            }
            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }
        
        // Return the result in sorted order
        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};
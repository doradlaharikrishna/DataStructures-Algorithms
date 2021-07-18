/**
Question:

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        /**
          1. First we find the starting index of an actual sorted array
          2. Loop breaks when left == right which is actual start point
        */
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            /**
              This is unusual in a sorted array. so we deep dive into unusual part 
              which is right side
            */
            if(nums[mid] > nums[right]) 
                left = mid + 1;
            else
                right = mid;
        }
        
        /**
          Now we do binary_search on appropriate side as we know the starting point
        */
        int start = left;
        left = 0, right = nums.size() - 1;
        
        // We basically find on which side we could find our target and set left, right accordingly.
        if(target >= nums[start] && target <= nums[right])
            left = start;
        else
            right = start -1;
        
        // Actual binary_search with processed left and right indexes
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};


// Time Complexity = logn + logn => O(log n). Space => O(1)

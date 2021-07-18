class Solution {
    
    int binarySearch(int left, int right, int target, vector<int>& nums) {
        if(left > right)
            return -1;
        int mid = (left + right)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            return binarySearch(mid+1, right, target, nums);
        else
            return binarySearch(left, mid-1, target, nums);
    }
    
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, target, nums);
    }
};

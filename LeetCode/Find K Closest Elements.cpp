/**
Question:
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-1;
        vector<int> res;
        int mid;
        if(arr.size()==1){
            res.push_back(arr[0]);
            return res;
        }
        while(left<=right){
            mid = left + (right - left)/2;
            if(arr[mid] == x){
                break;
            } else if(arr[mid] > x){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    
        int i = mid, j = mid;
        long leftNum, rightNum;
        if(i-1>=0){
            i--;
        } else {
            j++;
        }
    
        while(res.size() < k){
            leftNum = (i>=0) ? arr[i] : INT_MAX-1;
            rightNum = (j<=(arr.size()-1)) ? arr[j] : INT_MAX-1;
            if (abs(leftNum - x) <= abs(rightNum - x)) {
                res.push_back(leftNum);
                i--;
            } else {
                res.push_back(rightNum);
                j++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

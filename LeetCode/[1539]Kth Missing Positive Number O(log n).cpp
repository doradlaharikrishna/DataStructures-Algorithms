/**
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.


Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
*/

/**
Binary Search : O(logn)
Arr[i]:          [2,3,4,7,11], k=5
Index (i):       [0,1,2,3, 4], 
arr[i]-(i+1):    [1,1,1,3, 6],

left=0, right=4, mid=2, arr[mid]-(mid+1) = 1 < k so left=mid+1
left=3, right=4, mid=3, arr[mid]-(mid+1) = 3 < k so left=mid+1
left=4, right=4, mid=4, arr[mid]-(mid+1) = 6 > k so right=mid-1
left=4, right=3, loop break.
Kth Missing positive is between arr[left]=11 and arr[right]=7
The number of integers missing before arr[right] is 
     arr[right] - right - 1
The number to return is:
     arr[right] + k - (arr[right] - right - 1) = k + right + 1 = k+ left
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left =0, right = arr.size()-1;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(arr[mid]-mid-1 < k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left + k;
    }
};

class Solution {
    int squareRoot(int left, int right, int target) {
        int result = 0;
        while(left <= right) {
            long mid = left + (right - left) / 2;
            if((mid * mid) == target) {
                result = mid;
                break;
            } else if((mid * mid) < target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
public:
    int mySqrt(int x) {
        if ( x== 0)
            return 0;
        return squareRoot(0, x, x);
    }
};

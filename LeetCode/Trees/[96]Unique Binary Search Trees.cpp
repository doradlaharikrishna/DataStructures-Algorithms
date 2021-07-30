/**
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1
 

Constraints:
1 <= n <= 19
*/
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        
        for(int i=1;i<=n;i++){
            if(i<=2) {
                dp[i] = i;
                continue;
            }
            
            dp[i] = 0; // Initialize 0 and then change to actual value.
            
            for(int j =0;j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

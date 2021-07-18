/**

Question:

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:
Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:
Input: grid = [[-1]]
Output: 1
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int row = 0, column = grid[0].size()-1;
        while(row < grid.size() && column >=0){
            if(grid[row][column] < 0){ // if a grid[i][j] value is < 0 then all the below elements in the same column will also be < 0 as it is in decreasing order
                count = count + grid.size() - row; // (grid.size() - i) this counts the no of negative values
                column--;
            }else{
                row++; // if a grid[i][j] is >=0 then all left side values will be >=0 due to decreasing order condition then we shift to new row.
            }
        }
        return count;
    }
};

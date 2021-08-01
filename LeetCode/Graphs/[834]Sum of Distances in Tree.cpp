/**
Question:
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.


Example 1:
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.


Example 2:
Input: n = 1, edges = []
Output: [0]


Example 3:
Input: n = 2, edges = [[1,0]]
Output: [1,1]
 

Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
The given input represents a valid tree.
*/

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> v[n];
        vector<int> res;
        for ( int a=0;a<edges.size();a++) {
            v[edges[a][1]].push_back(edges[a][0]);
            v[edges[a][0]].push_back(edges[a][1]);
        }
        unordered_map<int, int> visited;
        queue<int> que;
        int level;
        int distance;
        for ( int i = 0; i < n; i++) {
            que.push(i);
            distance = 0;
            level = 1;
            visited.clear();
            while(!que.empty()) {
                int qsize = que.size();
                for (int k = 0; k < qsize; k++) {
                    int num = que.front();
                    if (visited[num] == 0) {
                        visited[num] = 1;
                        for(int j = 0; j < v[num].size(); j++) {
                            if(visited[v[num][j]] == 0) {
                                distance = distance + level;
                                que.push(v[num][j]);
                            }
                        }
                    }
                    que.pop();
                }
                level++;
            }
            res.push_back(distance);
        }
        return res;
    }
};

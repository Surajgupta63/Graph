// Using BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();
        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;
    
        vector<vector<int>> directions = {{1,1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                int i = node.first;
                int j = node.second;

                if(i == m-1 && j == n-1) return level+1;

                for(auto &dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == 0){
                        q.push({i_, j_});
                        grid[i_][j_] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

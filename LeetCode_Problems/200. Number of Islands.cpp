// Using (DFS)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void DFS(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';
        for(auto &dir : directions){
            int row_ = row + dir[0];
            int col_ = col + dir[1];
            
            if(row_ >= 0 && row_ < m && col_ >= 0 && col_ < n && grid[row_][col_] == '1'){
                DFS(grid, row_, col_);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int islands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};

// Using Multi-Source BFS
// T.C: O(m*n)
// S.C: O(1)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto &dir : directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < m && j_ >=0 && j_ < n && grid[i_][j_] == 1){
                        grid[i_][j_] = 2;
                        q.push({i_, j_});
                    }
                }
            }
            if(!q.empty()) time++;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};

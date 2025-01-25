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

// Using Dijkstra's Algorithm (Prioriy_Queue)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();
        if(m == 0 || n == 0 || grid[0][0] != 0) return -1;
    
        vector<vector<int>> directions = {{1,1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        typedef pair<int, pair<int, int>> P;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            int x = node.first;
            int y = node.second;

            for(auto &dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_] == 0 && d + 1 < result[x_][y_]){
                    pq.push({d+1, {x_, y_}});
                    result[x_][y_] = d+1;
                }
            }

        }

        if(result[m-1][n-1] == INT_MAX) return -1;
        return result[m-1][n-1]+1;
    }
};

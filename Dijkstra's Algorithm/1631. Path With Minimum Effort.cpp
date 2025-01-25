// Using Dijkstra's Algorithm
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        typedef pair<int, pair<int, int>> P;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            int x = node.first;
            int y = node.second;

            if(x == m-1 && y == n-1) return diff;

            for(auto &dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n){
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);

                    if(maxDiff < result[x_][y_]){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }


        }
        return result[m-1][n-1];
    }
};

// Using Diameter Concept with BFS
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
public:

    pair<int, int> findFarthest(unordered_map<int, vector<int>> &adj, int u){
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(u);
        visited[u] = true;

        int farthestNode = u;
        int dist = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int curr = q.front();
                q.pop();

                farthestNode = curr;

                for(int &v : adj[curr]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            if(!q.empty()) dist++;
        }
        return {farthestNode, dist};
    }

    int findDiameter(unordered_map<int, vector<int>> &adj){
        auto [farthestNode, distance] = findFarthest(adj, 0);

        auto [nextEndNode, diameter] = findFarthest(adj, farthestNode);

        return diameter;
    }
    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int jointDiameter = (d1+1)/2 + (d2+1)/2 + 1; 

        return max({d1, d2, jointDiameter});
    }
};

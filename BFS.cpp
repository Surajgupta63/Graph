// BFS Traversal
// T.C : O(V+E)
// S.C : O(V)
class Solution{
    public:
    void BFS(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<int> &ans){
        queue<int> q;
        q.push(u);
        visited[u] = true;
        ans.push_back(u);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int &v : adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    ans.push_back(v);
                }
            }
        }
        
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> ans;
        
        BFS(adj, 0, visited, ans);
        
        return ans;
    }     
};

// Using DFS and taking a adj list 
// T.C : O(V+E)
// S.C : O(V + V*E)
class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited){
        visited[u] = true;
        for(int & v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V, false);

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        int count = 0;
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                DFS(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};

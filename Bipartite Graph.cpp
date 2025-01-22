// Using DFS
class Solotion{
  public:
    bool isBipartiteDFS(vector<vector<int>>& adj, int curr, vector<int> &color, int currColor){
        color[curr] = currColor;
        
        for(int &v : adj[curr]){
            if(color[v] == color[curr]) return false;
            
            if(color[v] == -1){
                if(isBipartiteDFS(adj, v, color, !currColor) == false) return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);
        
        for(int i=0; i<V; i++){
            if(color[i] == -1 && isBipartiteDFS(adj, i, color, 1) == false){
                return false;
            }
        }
        return true;
    }
};

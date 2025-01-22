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

// Using BFS
class Solution{
  public:
    bool isBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int> &color, int currColor){
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;
        
        while(!q.empty()){
            int newCurr = q.front();
            q.pop();
            
            for(int &v : adj[newCurr]){
                if(color[v] == color[newCurr]) return false;
                if(color[v] == -1){
                    color[v] = 1 - color[newCurr];
                    q.push(v);
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);
        
        for(int i=0; i<V; i++){
            if(color[i] == -1 && isBipartiteBFS(adj, i, color, 1) == false){
                return false;
            }
        }
        return true;
    }
};

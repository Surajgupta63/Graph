// T.C : O(V+E)
// S.C : O(V)
class Solution{
  public:
    void DFS(vector<int>adj[], int u, vector<bool> &visited){
        visited[u] = true;
        
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }
    
    bool isConnected(int V, vector<int>adj[]){
        int nonZeroDegree = -1;
        for(int i=0; i<V; i++){
            if(adj[i].size() > 0){
                nonZeroDegree = i;
                break;
            }
        }
        
        vector<bool> visited(V, false);
        DFS(adj, nonZeroDegree, visited);
        
        for(int i=0; i<V; i++){
            if(visited[i] == false && adj[i].size() > 0) return false;
        }
        return true;
    }

	int isEulerCircuit(int V, vector<int>adj[]){
	    
	    if(isConnected(V, adj) == false) return 0;
	    
	    int oddDegree = 0;
	    
	    for(int i=0; i<V; i++){
	        if(adj[i].size() % 2 != 0) oddDegree++;
	    }
	    
	    if(oddDegree > 2) return 0;
	    if(oddDegree == 2) return 1;
	    
	    return 2;
	}
};

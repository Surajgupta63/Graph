
class Soltion{
  public:
  
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(x == parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) return;
        
        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y] += 1;
        }
        
    }
  
    int KruskalsAlgorithm(vector<vector<int>> vec, int V){
        int sum = 0;
        for(auto &temp : vec){
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v){
                Union(u, v);
                sum += w;
            }
        }
        
        return sum;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        parent.resize(V);
        rank.resize(V, 0);
        vector<vector<int>> vec;
        
        for(int i=0; i<V; i++){
            parent[i] = i;
        }
        
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                int u = i;
                int v = it[0];
                int w = it[1];
                
                vec.push_back({u, v, w});
            }
        }
        
        auto comp = [&](vector<int> &vec1, vector<int> &vec2){
            return vec1[2] < vec2[2]; 
        };
        
        sort(vec.begin(), vec.end(), comp);
        
        return KruskalsAlgorithm(vec, V);
    }
};

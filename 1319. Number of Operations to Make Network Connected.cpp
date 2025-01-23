// Using Disjoint Set Union (DSU)
// T.C : O(V+E)
// T.C : O(V)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }

        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]  += 1;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        rank.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        int ans = n;
        for(auto &edge : connections){
            int x_parent = find(edge[0]);
            int y_parent = find(edge[1]);

            if(x_parent != y_parent){
                Union(x_parent, y_parent);
                ans--;
            }

        }
        return ans-1;
    }
};

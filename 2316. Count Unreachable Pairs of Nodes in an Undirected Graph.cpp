// Using DSU
// T.C : O(V + E)  + O(V)
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(auto &edge : edges){
            int x_parent = (edge[0]);
            int y_parent = (edge[1]);

            Union(x_parent, y_parent);
        }

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[find(i)]++;
        }
        
        long long ans = 0;
        long long rem = n;
        for(auto it : mp){
            ans += it.second * (rem - it.second);
            rem = rem - it.second;
        }
        return ans;
    }
};

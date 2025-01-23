// Using DSU
// T.C : O(V+E)
// S.C : O(V)
class Solution {
public:
    int find(int x, vector<int> &parent){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int> &parent,vector<int> &rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 1);
        int n = equations.size();
        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(string &s : equations){
            if(s[1] == '='){
                Union(s[0]-'a', s[3]-'a', parent, rank);
            }
        }

        for(string &s : equations){
            if(s[1] == '!'){
                int x_parent = find(s[0]-'a', parent);
                int y_parent = find(s[3]-'a', parent);

                if(x_parent  == y_parent) return false;
            }
        }
        return true;
    }
};

// Disjoint Union Set DSU Implementation
int find(int i, vector<int> parent){
    if(i == parent[i]) return i;

    return find(parent[i], parent);
}

void DSUunion(int x, int y, vector<int> parent){
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if(x_parent != y_parent){
        parent[x_parent] = y_parent;
    }
}

// Disjoint Set Union By Rank and Path Compression
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

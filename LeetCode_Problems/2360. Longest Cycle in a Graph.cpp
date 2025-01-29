// Using DFS
// T.C : O(V+E)
// S.C : O(V+E)
class Solution {
public:
    int result = -1;
    void DFS(vector<int>& edges, int u, vector<bool>& visited, vector<bool>& inRecur, vector<int>& count){
        visited[u] = true;
        inRecur[u] = true;
        int v = edges[u];
        if(v != -1){
            if(!visited[v]){
                count[v] = count[u] + 1;
                DFS(edges, v, visited, inRecur, count);
            }
            else if(inRecur[v]){
                int cycleLen = count[u] - count[v] + 1;
                result = max(result, cycleLen);
            }
        }
        inRecur[u] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> inRecur(n, false);
        vector<int> count(n, 1);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFS(edges, i, visited, inRecur, count);
            }
        }

        return result;
    }
};

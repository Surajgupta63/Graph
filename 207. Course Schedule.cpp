// Using BFS (Detectiong Cycle using Kahn's Algorithm)
// T.C : O(V + E)
// S.C : O(V + E + V)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> q;
        int count = 0;
        for(int u=0; u<numCourses; u++){
            if(indegree[u] == 0){
                count++;
                q.push(u);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }

        if(count == numCourses) return true;
        return false;
        
    }
};


class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false;
        }
        
        return true;
    }
};

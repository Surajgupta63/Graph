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

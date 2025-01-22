// Using BFS Kahn's Algorithm
// T.C : O(V + E)
// S.C : O(V + E)
class Solution {
public:
    vector<int> topoSortCourses(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        queue<int> q;
        int count = 0;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                count++;
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }

        if(count == n) return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;

        for(auto &vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);

            indegree[v]++;
        }

        return topoSortCourses(adj, numCourses, indegree);
    }
};

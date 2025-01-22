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

// Using DFS + Cycle Detection
class Solution {
public:
    void topoSortCourses(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &currRec, stack<int> &st, bool &isCycle){
        visited[u] = true;
        currRec[u] = true;

        for(int &v : adj[u]){
            if(!visited[v])
                topoSortCourses(adj, v, visited, currRec, st, isCycle);
            else if(currRec[v]){
                isCycle = true; 
                return;
            }
        }
        currRec[u] = false;
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> currRec(numCourses, false);
        stack<int> st;
        unordered_map<int, vector<int>> adj;

        for(auto &vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            adj[u].push_back(v);
        }

        bool isCycle = false;
        for(int i=0; i<numCourses; i++){
            if(!visited[i])
                topoSortCourses(adj, i, visited, currRec, st, isCycle);

        }

        if(isCycle) return {};

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

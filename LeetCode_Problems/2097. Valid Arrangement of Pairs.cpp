// Using Euler Circuit (DFS)

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // build adj list
        unordered_map<int, vector<int>> adj;

        // build indegree and outdegree
        unordered_map<int, int> indegree, outdegree;

        // let's build
        for(auto &edge : pairs){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        
        // start node pata kar lo bhai
        int startNode = pairs[0][0];
        for(auto &it : adj){
            int node = it.first;
            if(outdegree[node] -  indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        // ab wahi apna khandani DFS kar lo 
        vector<int> EulerPath;
        stack<int> st;
        st.push(startNode);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }else{
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        reverse(EulerPath.begin(), EulerPath.end());

        vector<vector<int>> ans;

        for(int i=0; i<EulerPath.size()-1; i++){
            ans.push_back({EulerPath[i], EulerPath[i+1]});
        }
        return ans;
    }
};

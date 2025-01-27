// Using Prim;s Algorithm
// T.C : O(Elog(E))
// T.C : O(V)
class Solution {
public:
    typedef pair<int, int> P;
    int primsMST(vector<vector<P>> &adj, int V){
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> inMST(V, false);
        pq.push({0, 0});
        int sum = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(inMST[node]) continue;
            inMST[node] = true;
            sum += dist;

            for(auto p : adj[node]){
                int adjNode = p.first;
                int adjDist = p.second;

                if(!inMST[adjNode]){
                    pq.push({adjDist, adjNode});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>> adj(V);

        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return primsMST(adj, V);
    }
};

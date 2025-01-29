// T.C : O(N)
// S.C : O(N);
class Solution{
  public:
  void DFS(vector<int> &Edge, int u, vector<int> &visited, vector<int> &inRecur, int &cycleNode){
      visited[u] = true;
      inRecur[u] = true;
      int v = Edge[u];
      if(v != -1){
          if(!visited[v]){
              DFS(Edge, v, visited, inRecur, cycleNode);
          }
          else if(inRecur[v]){
              cycleNode = v;
          }
      }
      inRecur[u] = false;
  }
  long long largestSumCycle(int N, vector<int> Edge){
    int n = Edge.size();
    vector<int> visited(n, false);
    vector<int> inRecur(n, false);
    int result = -1;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int cycleNode = -1;
            DFS(Edge, i, visited, inRecur, cycleNode);
            
            if(cycleNode != -1){
                int sum = 0;
                sum += cycleNode;
                vector<bool> vis(n, 0);
                
                vis[cycleNode] = true;
                int nextNode = Edge[cycleNode];
                
                while(!vis[nextNode]){
                    vis[nextNode] = true;
                    sum += nextNode;
                    nextNode = Edge[nextNode];
                }
                result = max(result, sum);
            }
        }
    }
    return result;
};

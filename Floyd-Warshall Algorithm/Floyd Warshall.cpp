// FLoyd-Warshall Algorithm
// T.C : O(N^3)
// S.C : O(1)
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& grid){
        int n = grid.size();
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == -1)
                    grid[i][j] = 100000;
                
            }
        }
        
        for(int via = 0; via < n; via++) {
            
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    
                   grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    
                }
            }
        }
        
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 100000)
                    grid[i][j] = -1;
                
            }
        }
	}
};

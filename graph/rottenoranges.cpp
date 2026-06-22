class Solution{
public:
  //cant solve this q using dfs we have to go level by level to find minimum number of days 
    int orangesRotting(vector<vector<int>> &grid) {
      int m=grid.size();
      int n=grid[0].size();
      queue<pair<int,int>>q;
      int ans = 0;
      int total = 0;
      int count = 0;
      for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j] != 0){
            total++;
          }
          if(grid[i][j] == 2){
            q.push({i,j});
          }
        }
      }
      int dx[4] = {0,0,1,-1};
      int dy[4] = {-1,1,0,0};
      while(!q.empty()){
        count += q.size();
        int k = q.size();
        while(k--){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= m || ny >= n || nx <0 || ny<0 || grid[nx][ny] != 1){
              continue;
            }
            grid[nx][ny] = 2;
            q.push({nx,ny});
          }
        }
        if(!q.empty()){
          ans++;
        }
      }
      return total == count ? ans:-1;
    }
};



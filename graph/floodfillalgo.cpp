class Solution{
    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor) {
      int m = image.size();
      int n = image[0].size();
      int oldColor = image[sr][sc];
      if(oldColor == newColor) return image;
      queue<pair<int,int>>q;
      q.push({sr,sc});
      image[sr][sc] = newColor;
      int dx[4] = {0,0,1,-1};
      int dy[4] = {1,-1,0,0};
      while(!q.empty()){
        int k = q.size();
        while(k--){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= m || ny >= n || nx <0 || ny<0 || image[nx][ny] != oldColor){
              continue;
            }
            image[nx][ny] = newColor;
            q.push({nx,ny});
          }
        }
      }
      return image;
    }
};

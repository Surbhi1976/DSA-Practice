class Solution {
  public:
    void dfs(vector<int>graph[],vector<bool>&visited,int i){
      visited[i] = true;
      for(auto&it:graph[i]){
        if(!visited[it]){
        dfs(graph,visited,it);}
      }
    }
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
      vector<int>graph[V];
      for(int i=0;i<edges.size();i++){
        int j=edges[i][0];
        int k=edges[i][1];
        graph[j].push_back(k);
        graph[k].push_back(j);
      }
      int count = 0;
      vector<bool>visited(V,false);

      for(int i = 0;i<V;i++){
        if(!visited[i]){
          count++;
          dfs(graph,visited,i);
        }
      }
      return count;
    }
};

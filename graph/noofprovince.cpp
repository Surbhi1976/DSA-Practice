//No of province

int noofprovince(vector<vector<int>>&adj){
  int n = adj.size();
  vector<int>graph[n];
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(adj[i][j] == 1 && i!=j){
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }

  vector<bool>visited(n,false);
  int count = 0;
  for(int i=0;i<n;i++){
      if(!visited[i]){
        count++;
        dfs(graph,visited,i);
      }
    
  }
  return count;
}

void dfs(vector<int>graph[],vector<bool>&visited,int it){
  visited[it] = true;
  for(auto&i:graph[it]){
    if(visited[i] != true){
      dfs(graph,visited,i);
    }
  }
}

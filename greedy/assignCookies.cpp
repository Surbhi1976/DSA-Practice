//memoization

int assignCookies(vector<int>&student,vector<int>&cookies){
  int n=student.size();
  int m=cookies.size();
  sort(student.begin(),student.end());
  sort(cookies.begin(),cookies.end());
  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  return helper(0,0,student,cookies,dp);
}

int helper(int stindx,int coindx,vector<int>&student,vector<int>&cookies,vector<vector<int>>&dp){
  if(stindx >= student.size() || coindx >= cookies.size()){
    return 0;
  }
  if(dp[stindx][coindx] != -1){
    return dp[stindx][coindx];
  }
  int skip = helper(stindx,coindx+1,student,cookies,dp);
  int take = 0;
  if(student[stindx] <= cookies[coindx]){
    take = 1 + helper(stindx+1,coindx+1,student,cookies,dp);
  }
  return dp[stindx][coindx] = max(take,skip);
}


//tabulation

int assignCookies(vector<int>&student,vector<int>&cookies){
  int n=student.size();
  int m=cookies.size();
  sort(student.begin(),student.end());
  sort(cookies.begin(),cookies.end());
  vector<vector<int>>dp(n+1,vector<int>(m+1,0);
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      int take = 0;
      int skip = dp[i][j+1];
      if(student[i] <= cookies[j]){
        take = 1 + dp[i+1][j+1];
      }
      dp[i][j] = max(take,skip);
    }
  }
  return dp[0][0];
}

//optimal

int assignCookies(vector<int>&student,vector<int>&cookies){
  int n=student.size();
  int m=cookies.size();
  sort(student.begin(),student.end());
  sort(cookies.begin(),cookies.end());

  int ans = 0;
  int stidx = 0;
  int coidx = 0;
  while(stidx < n && coidx < m){
    if(student[stidx] <= cookies[coidx]){
      ans+=1;
      stidx++;
    }
    coidx++;
  }
  return ans;
}

class Solution{
public:
    bool equalPartition(int n, vector<int> arr) {
      int sum = 0;
      for(int i=0;i<arr.size();i++){
        sum+=arr[i];
      }
      if(sum % 2 == 1) return false;
      int target = sum/2;
      vector<vector<int>>dp(n,vector<int>(target+1,-1));
      
      return solve(n-1,target,arr,dp);
    }
};

//memoization
bool solve(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
  if(target==0) return true;
  if(idx == 0) {
    if(arr[0] == target) return true;
  }
  if(dp[idx][target] != -1) return dp[idx][target];
  bool take = false;
  if(arr[idx] <= target) take = solve(idx-1,target-arr[idx],arr,dp);
  bool nontake = solve(idx-1,target,arr,dp);
  return dp[idx][target] = take || nontake;
}

//tabulation

bool solve(vector<int>&arr,vector<vector<int>>&dp,int target){
  for(int i=0;i<n;i++){
    dp[i][0] = true;
  }
  if(arr[0] <= target) dp[0][arr[0]]=true;
  for(int i=1;i<n;i++){
    for(int j=1;j<=target;j++){
      bool take = false;
      if(arr[i] <= j) take = dp[i-1][j-arr[i]];
      bool nontake = dp[i-1][j];
      dp[i][j] = take || nontake;
    }
  }
  return dp[n-1][target];
}

//space optimzation

bool solve(vector<int>&arr,int target){
  int n=arr.size();
  vector<int>prev(target+1,0),cur(target+1,0);
  prev[0]=cur[0]=1;
  if(arr[0]<=target) {
    prev[arr[0]]=1;
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<=target;j++){
      bool take = false;
      if(arr[i]<=j) take=prev[j-arr[i]];
      bool nontake = prev[j];
      cur[j]=take || nontake;
    }
    swap(prev,cur);
    fill(cur.begin(),cur.end(),0);
    cur[0]=1;
  }
  return prev[target];
}

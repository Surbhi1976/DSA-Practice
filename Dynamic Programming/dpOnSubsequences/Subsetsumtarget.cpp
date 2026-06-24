class Solution{   
public:
    bool solve(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
      if(idx == 0) {
        if(target == 0 || arr[0] == target) return true;
        return false;
      }
      if(target == 0) return true;
      if(dp[idx][target] != -1) return dp[idx][target];
      bool take = false;
      if(arr[idx] <= target) take = solve(idx-1,target-arr[idx],arr,dp);
      bool nontake = solve(idx-1,target,arr,dp);
      return dp[idx][target]=take || nontake;
    }
    bool isSubsetSum(vector<int>arr, int target){
      int n=arr.size();
      vector<vector<int>>dp(n,vector<int>(target+1,-1));
      return solve(n-1,target,arr,dp);
    }
};
//O(n*target)
//O(n*target) + O(n)

//tabulation

bool solve(vector<int>&arr,int target){
  int n = arr.size();
  vector<vector<int>>dp(n,vector<int>(target+1,0));
  for(int i=0;i<n;i++){
    dp[i][0] = true;
  }
  if(arr[0] <= target){
    dp[0][arr[0]] = true;
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<=target;j++){
      bool nontake = dp[i-1][j];
      bool take = false;
      if(arr[i] <= j){
        take = dp[i-1][j-arr[i]];
      }
      dp[i][j] = take || nontake;
    }
  }
  return dp[n-1][target];
}

//O(n*target)
//O(n*target)

//space optimization

bool solve(vector<int>&arr,int target){
  int n=arr.size();
  vector<int>prev(target+1,0),curr(target+1,0);
  prev[0]=curr[0]=1;
  if(arr[0] <= target) prev[arr[0]] = 1;
  for(int i=1;i<n;i++){
    for(int j=1;j<=target;j++){
      bool nontake = prev[j];
      bool take = false;
      if(arr[i] <= j) take = prev[j-arr[i]];
      curr[j] = take || nontake;
    }
    swap(prev,curr);
    fill(curr.begin(),curr.end(),0);
    curr[0] = 1;
  }
  return prev[target];
}
//O(n*target)
//O(target)

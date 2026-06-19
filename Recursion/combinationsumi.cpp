vector<vector<int>>combinationsumi(vector<int>&nums,int target){
  int n=nums.size();
  vector<vector<int>>ans;
  vector<int>ds;
  findans(0,nums,target,ds,ans);
  return ans;
}

void findans(int ind,vector<int>&nums,int target,vector<int>&ds,vector<vector<int>>&ans){
  if(ind == nums.size()){
    if(target == 0){
      ans.push_back(ds);
    }
    return;
  }
  if(nums[ind] <= target){
    ds.push_back(nums[ind]);
    findans(ind,nums,target-nums[ind],ds,ans);
    ds.pop_back();
  }
  findans(ind+1,nums,target,ds,ans);
}

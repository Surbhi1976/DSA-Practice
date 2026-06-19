bool canJump(vector<int>&nums){
  int finalidx = 0;
  for(int i=0;i<nums.size();i++){
    if(finalidx < i){
      return false;
    }
    finalidx = max(finalidx,i+nums[i]);
  }
  return true;
}



//find numbers whose binary form do not have consecutive ones

// idx   ,    tight    ,    prev
//no leadingzero as it is binary and consecutive ones has no prob with that 
int dp[30][2][2];
int countconsones(int n){
  string s = bitset<32>(n).to_string();
  int firstidx = s.find('1');
  s=s.substr(firstidx);
  memset(dp,-1,sizeof(dp));
  return solve(s,0,1,0);
}

int solve(string s,int idx,bool tight,bool prev){
  if(idx == s.size()) return 1;
  if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];
  int lb=0;
  int ub = (tight)?s[idx]-'0':1;
  int res= 0;
  for(int i=lb;i<=ub;i++){
    if(prev && i==1) continue;
    res += solve(s,idx+1,tight&&i==ub,i==1);
  }
  return dp[idx][tight][prev] = res;
}

//total number of 1 in the digits from 0 to all the numbers till n
//idx   ,    tight    ,    countof1
int dp[11][2][10];
int countdigitone(int n){
  return solve(n);
}

int solve(int n){
  string a = to_string(n);
  memset(dp,-1,sizeof(dp));
  return dp_func(a,0,1,0);
}

int dp_func(string a,int idx,bool tight,int cntof1){
  if(idx == a.size()) return cntof1;
  if(dp[idx][tight][cntof1] != -1) return dp[idx][tight][cntof1];
  int lb=0;
  int up=(tight==true)?(a[idx]-'0'):9;
  int res = 0;
  for(int i=lb;i<=up;i++){
    res += dp_func(a,idx+1,(tight && i==up),cntof1 + (i==1));
  }
  return dp[idx][tight][cntof1]= res;
}

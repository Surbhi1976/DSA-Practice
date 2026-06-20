//return number of positive integers that have atleast one repeated digit

//idx   ,    tight    ,    repetition    ,     mask    ,     leadingzero
int dp[20][2][2][1023][2];
int numWithRepeatedDigit(int n){
  return solve(n);
}

int solve(int n){
  string a = to_string(n);
  memset(dp,-1,sizeof(dp));
  return dp_func(a,0,1,0,0,1);
}

int dp_func(string a,int idx,bool tight,bool repeat,int mask,bool lz){
  if(idx == a.size()) return repeat;
  if(dp[idx][tight][repeat][mask][lz] != -1) return dp[idx][tight][repeat][mask][lz];
  int lb = 0;
  int ub = (tight) ? a[idx]-'0':9;
  int res = 0;
  for(int i=lb;i<=ub;i++){
    if(lz && i==0){
      res += dp_func(a,idx+1,(tight && i == ub),0,mask,1);
    }
    else{
      bool isdigitused = mask & (1<<i);
      res += dp_func(a,idx+1,(tight && i == ub),repeat || isdigitused,mask | (1<<i),0);
    }
  }
  return dp[idx][tight][repeat][mask][lz] = res;
}

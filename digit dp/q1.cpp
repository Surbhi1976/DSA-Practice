//count the numbers that have no adjacent digits same between the given range

//idx  ,  tight  ,   prev   ,   leadzero
typedef long long ll;
long long dp[20][11][2][2];

long long findnumber(long long a,long long b){
  return solve(a,b);
}

long long solve(long long a,long long b){
  string l=to_string(a-1);
  memset(dp,-1,sizeof(dp));
  long long mn= dp_func(l,1,10,0,1);
  string r=to_string(b);
  memset(dp,-1,sizeof(dp));
  long long mx= dp_func(r,1,10,0,1);
  return mx-mn;
}

long long dp_func(string a,bool tight,int prev,ll idx,int leadzero){
  if(idx==a.size()) return 1;
  if(dp[idx][prev][tight][leadzero] != -1) return dp[idx][prev][tight][leadzero];
  long long lb=0;
  long long ub=(tight == true) ? (a[idx]-'0') : 9;
  ll res = 0;
  for(int i=lb;i<=ub;i++){
    if(i == prev && leadzero == false) continue;
    res += dp_func(a,(tight==true && i==ub)?1:0,i,idx+1,(leadzero && i==0));
  }
  return dp[idx][prev][tight][leadzero] = res;
}

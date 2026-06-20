//count good integers in a range in which adjacent digits have a difference atmost k
class Solution {
public:
    //idx , tight , prev , start
    int K;
    long long dp[16][2][12][2];
    long long dp_func(string a,int idx,bool tight,int prev,bool start){
        if(idx == a.size()) return start?1:0;
        if(dp[idx][tight][prev][start] != -1) return dp[idx][tight][prev][start];
        int lb=0;
        int ub=tight?a[idx]-'0':9;
        long long res = 0;
        for(int i=lb;i<=ub;i++){
            if(!start && i==0) res+=dp_func(a,idx+1,tight&&i==ub,prev,0);
            else{
            if(start && abs(i-prev) > K) continue;
            res += dp_func(a,idx+1,tight&&i==ub,i,1);
        }}
        return dp[idx][tight][prev][start] = res;
    }
    long long solve(long long l, long long r, int k){
        long long l2 = l-1;
        string l1=to_string(l2);
        memset(dp,-1,sizeof(dp));
        long long lt = dp_func(l1,0,1,10,0);
        string r1=to_string(r);
        memset(dp,-1,sizeof(dp));
        long long rt = dp_func(r1,0,1,10,0);
        return rt-lt;
    }
    long long goodIntegers(long long l, long long r, int k) {
        K=k;
        return solve(l,r,k);
    }
    
};©leetcode

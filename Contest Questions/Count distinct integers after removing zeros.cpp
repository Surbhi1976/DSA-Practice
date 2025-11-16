class Solution {
public:
    string s;
    long long dp[20][2][2];
    
    long long dfs(int pos, int tight, int started) {
        if (pos == s.size())
            return started ? 1 : 0;

        if (dp[pos][tight][started] != -1)
            return dp[pos][tight][started];

        int limit = tight ? (s[pos] - '0') : 9;
        long long ans = 0;

        for (int d = 0; d <= limit; d++) {

            int ntight = (tight && d == limit);
            int nstarted = started;

            if (!started) {
                if (d == 0) {
                    nstarted = 0;
                } else {
                    nstarted = 1;
                }
            } else {
                if (d == 0) continue; 
            }

            ans += dfs(pos + 1, ntight, nstarted);
        }

        return dp[pos][tight][started] = ans;
    }

    long long countDistinct(long long n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(0, 1, 0);
    }
};

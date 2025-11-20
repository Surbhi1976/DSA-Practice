class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int a = -1, b = -1, ans = 0;
        
        for (auto &it : intervals) {
            int l = it[0], r = it[1];
            bool hasA = (a >= l);
            bool hasB = (b >= l);
            
            if (hasA && hasB) continue;
            if (hasB) {
                ans++;
                a = b;
                b = r;
            } else {
                ans += 2;
                a = r - 1;
                b = r;
            }
        }
        return ans;
    }
};

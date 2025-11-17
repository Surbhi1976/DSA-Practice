class Solution {
public:
    int m=1e9+7;

    int numberOfGoodPartitions(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>last_index;
        for(int i=0;i<n;i++){
            last_index[nums[i]]=i;
        }    
        int i=0;
        int j=0;
        j=max(j,last_index[nums[0]]);
        int result=1;
        while(i<n){
            if(i>j){
              result=result*2 %m;  
            }
            j=max(j,last_index[nums[i]]);
            i++;
        }
        return result;
    }
};

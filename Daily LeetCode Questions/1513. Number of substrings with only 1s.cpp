class Solution {
public:
    int numSub(string s) {
        long long count1=0;
        long long result=0;
        for(char c:s){
            if(c=='0'){
                result+=(count1)*(count1+1)/2;
                count1=0;
            }
            if(c=='1'){
                count1++;
            }
            
        }
        result+=(count1)*(count1+1)/2;
        return result;
    }
};

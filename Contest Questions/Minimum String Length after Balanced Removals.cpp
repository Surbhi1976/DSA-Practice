class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int counta=0;
        int countb=0;
        for(char c:s){
            if(c=='a'){
                counta++;
            }
            if(c=='b'){
                countb++;
            }
        }
        return abs(counta-countb);
    }
}

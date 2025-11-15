class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> cumcountone(n,0);
        cumcountone[0]=(s[0]=='1') ? 1 : 0;
        for(int i=1;i<n;i++){
            cumcountone[i]=cumcountone[i-1]+((s[i]=='1') ? 1 : 0);
        }
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int countone=cumcountone[j]- ((i-1>=0) ? cumcountone[i-1] : 0);
                int countzero=j-i+1-countone;

                if(countzero*countzero>countone){
                    int wasteindices=countzero*countzero-countone;
                    j+=wasteindices-1;
                }
                else if(countzero*countzero==countone){
                    result++;
                }
                else{
                    result+=1;
                    int k=sqrt(countone)-countzero;
                    int next=j+k;
                    if(next>=n){
                        result+=n-j-1;
                        break;
                    }
                    else{
                        result+=k;
                    }
                    j=next;
                }
            }
           
        }
         return result;
    }
};

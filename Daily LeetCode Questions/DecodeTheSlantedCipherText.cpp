class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n/rows;

        string original = "";

        for(int i=0;i<col;i++){
            int k=0;
            int j=i;
            while(k<rows && j<col){
                original.push_back(encodedText[k*col+j]);
                k++;
                j++;
            }
        }
        while(!original.empty() && original.back() == ' ') {
    original.pop_back();
}
        return original;
    }
};

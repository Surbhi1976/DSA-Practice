struct Node{
    Node*links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    //O(len)
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    //O(len)
    int countWordsEqualTo(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node= node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    //O(len)
    int countWordsStartWith(string prefix){
        Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(node->containsKey(prefix[i])){
                node = node -> get(prefix[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    //O(len)
    void erase(string word){
        if(countWordsEqualTo(word) == 0) return; // prevents counts from becoming negative

        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};

struct Node{
    Node* links[26] = {};
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }
};

class Trie{
    private : Node* root;

    public:
    Trie(){
        root = new Node();
    }

    public:
    void insert(string word){
        Node * node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
};

int countdistinctsubstrings(string word){
    int cnt = 0;
    Node* root = new Node();

    for(int i=0;i<word.size();i++){
        Node* node = root;
        for(int j=i;j<word.size();j++){
            if(!node->containsKey(word[j])){
                cnt++;
                node -> put(word[j],new Node());
            }
            node = node->get(word[j]);
        }
    }
    return cnt+1;
}

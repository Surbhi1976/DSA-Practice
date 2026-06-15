//to find the nth bit is set or not    :     (num >> n) & 1 == 1
//turn on the nth bit                  :     num || (1 << n)

struct Node{
    Node* links[2] = {};
    bool flag = false;

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit,Node* node){
        links[bit] = node;
    }
};

class Trie{
    private: Node* root;

    public:
    Trie(){
        root = new Node();
    }

    public:
    void insert(int a){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (a >> i) & 1;
            if(!node->containsKey(bit)){
                node -> put(bit,new Node());
            }
            node = node->get(bit);
        }

    }

    public:
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(node -> containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

//O(n+m)
int maxXor(int n,int m,vector<int>&arr1 , vector<int>&arr2){
    Trie trie;
    for(auto & it:arr1) trie.insert(it);
    int maxi = 0;
    for(auto & it:arr2){
        maxi = max(maxi , trie.getMax(it));
    }
    return maxi;
}

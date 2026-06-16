struct Tree{
    int val;
    Tree*left;
    Tree*right;

    Tree(int data){
        val = data;
        left = right = NULL;
    }
};

Tree* searchbst(Tree* root,int target){
    while(root != NULL && root->val != target){
        if(target < root->val){
            root = root->left;
        }
        else{
            root->right;
        }
    }
    return root;
}

Tree* minBST(Tree* root){
    if(root == NULL) return NULL;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Tree* maxBST(Tree* root){
    if(root == NULL) return NULL;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

int floorBSt(Tree* root,int x){ // floor = greatest value(<=x)
    int floor = -1;
    while(root != NULL){
        if(root -> val == x){
            floor = root->val;
            return floor;
        }

        if(root->val < x){
            floor = root->val;
            root = root->right;
        }

        else{
            root = root->left;
        }
    }
    return floor;
}

int ceilBST(Tree* root,int x){ // ceil = smallest value (>=x)
    int ceil = -1;
    while(root){
        if(root->val == x){
            ceil = root->val;
            return ceil;
        }

        if(root->val > x){
            ceil = root->val;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ceil;
}

Tree* insertBST(Tree* root,int val){
    if(root == NULL){
        return new  Tree(val);
    }

    Tree* curr = root;
    while(true){
        if(val < curr->val){
            if(curr->left != NULL){
                curr = curr->left;
            }
            else{
                curr->left = new Tree(val);
                break;
            }
        }
        else{                        //x = 5      1-2-3-7
            if(curr->right != NULL){  
                curr = curr->right;
            }
            else{
                curr->right = new Tree(val);
                break;
            }
        }
    }
    return root;

    //REcursive soln
    /*if(root == NULL){
    return new Tree(val)}
    if(val < root->val){
    root->left = insert(root->left,val);}
    else{
    root ->right = insert(root->right,val);}
    return root;*/
}

Tree* deleteNode(Tree* root,int x){
    if(root == NULL){
        return NULL;
    }

    if(x < root->val){
        root->left = deleteNode(root->left,x);
    }
    else if(x > root->val){
        root->right = deleteNode(root->right,x);
    }

    else{   //x == root->val
        //case 1 : left child NULL
        if(root -> left == NULL){
            Tree* temp = root->right;
            delete root;
            return temp;
        }

        //case 2 : right child NULL
        if(root -> right == NULL){
            Tree* temp = root->left;
            delete root;
            return temp;
        }

        //case 3 : have both child
        Tree* successor = findMin(root->right);
        root -> val = successor->val;
        root -> right = deleteNode(root->right,successor->val);

        /*Tree* findMin(Tree* root){
            if(root == NULL) return NULL;
            while(root -> next != NULL){
                root = root -> left;
            }
            return root;
        }*/
    }
    return root;
}

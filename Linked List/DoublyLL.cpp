class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node*next1,Node*prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }  

    Node(int data2){
        data = data2;
        next = NULL;
        prev = NULL;
    }
};

Node* convertVec2DLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i] , NULL,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* insertAtTail(Node* head,int k){
    Node* newNode = new Node(k);
    if(head == NULL){
        return newNode;
    }

    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
    return head;
}

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        head = curr;
        curr = temp;
    }

    return head;
}

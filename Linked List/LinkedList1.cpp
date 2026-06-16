class Node{
    public:
    int data;
    Node*next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data2){
        data = data2;
        next = NULL;
    }
};

class Solution{
    public:
    Node* insertatHead(Node* head,int dataa){
        Node*newNode = new Node(dataa,head);
        return newNode;
    }

    public:
    Node*deleteTail(Node* head){
        if(head == NULL || head->next == NULL){
            delete head;
            return NULL;
        }

        Node* curr = head;
        while(curr->next->next != NULL){
            curr = curr->next;
        }

        delete curr->next;
        curr->next = NULL;
        return head;
    }

    public:
    int lengthLL(Node* head){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    public:
    bool searchValue(Node* head,int key){
        Node* curr = head;
        while(curr != NULL){
            if(curr->data == key){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

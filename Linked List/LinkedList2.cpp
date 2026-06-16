class Node{
    public:
    int data;
    Node*next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int dataa){
        data = dataa;
        next = NULL;
    }
};

Node* findMiddle(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->fast->next;
    }

    return slow;
}

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        Node* front = temp->next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
                                            //otherwise we can have unordered map mp<Node*,int>
    while(fast != NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

Node* startingPointOfLoopLL(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            Node* p = head;
            while(p != slow){
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}

Node* lengthOfLoop(Node* head){
    Node* fast = head;
    Node* slow = head;
    int length = 0;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            length++;
            Node* temp = slow;
            while(temp->next != slow){
                temp = temp->next;
                length++;
            }
            return length;
        }
    }
    return 0;
}

Node* deleteMiddleNode(Node* head){
    if(head == NULL || head->next == NULL){
        delete head;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}

Node*  deleteNthNodeFromEnd(Node* head,int n){
    Node* dummy = new Node(0,head);

    Node* slow = dummy;
    Node* fast = dummy;

    for(int i=0;i<=n;i++){
        if(fast == NULL) return head;
        fast = fast->next;
    }

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return dummy->next;
}

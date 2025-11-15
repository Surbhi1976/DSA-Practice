/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthlist(ListNode * head){
        int l=0;
        while(head){
            head=head->next;
            l++;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node1=head;
        ListNode* node2=head;
        int l=lengthlist(head);
        int k1=k;
        while(k1>1){
            node1=node1->next;
            k1--;
        }
        int k2=l-k+1;
        while(k2>1){
            node2=node2->next;
            k2--;
        }
        swap(node1->val,node2->val);
        return head;
    }
};

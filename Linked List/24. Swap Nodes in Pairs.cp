ListNode* SwapPairs(ListNode* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  ListNode* temp=head->next;
  head->next=SwapPairs(head->next->next);
  temp->next=head;
  return temp;
}
  

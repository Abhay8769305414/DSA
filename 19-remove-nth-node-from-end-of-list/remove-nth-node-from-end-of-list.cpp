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
     int getSize(ListNode*head){
        int size=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return size;
    }
 
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        int size=getSize(head);
        if (n == size) {
    ListNode* newHead = head->next;
    delete head;
    return newHead;
}
        ListNode*prev=head;
        for(int i=1;i<(size-n);i++){
            prev=prev->next;
        }
        prev->next=prev->next->next;

        return head;
    }
};
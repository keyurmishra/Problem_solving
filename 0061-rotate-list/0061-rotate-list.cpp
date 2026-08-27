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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!k) return head;
        ListNode* current = head;
        int length=0;
        while(current!=nullptr){
            length++;
            current=current->next;
        }
        k=k%length;
        if(k==0) return head;
        current=head;
        for(int i = 0 ; i<length-k-1;i++){
            current=current->next;
        }
        ListNode* dummy = current->next;
        current->next=nullptr;
        ListNode* temp = dummy;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next= head;
        return dummy;
        
    }
};
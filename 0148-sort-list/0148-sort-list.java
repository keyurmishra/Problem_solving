/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next==null) return head;
        //using the concept of the merge sort we will solve this 
      
        ListNode slow=head;
        ListNode fast=head.next;
        // find out the middle one
        while(fast!=null && fast.next!=null){
           
            slow=slow.next;
            fast=fast.next.next;
        }
        //now break this into two section 
        ListNode newhead=slow.next;
        slow.next=null;
        ListNode right=sortList(head);
        ListNode left=sortList(newhead);
        return merge(right,left);
    }
    public ListNode merge(ListNode right,ListNode left){
        if(right==null){
            return left;
        }
        if(left==null){
            return right;
        }
        if(right.val <= left.val){
           right.next= merge(right.next,left);
           return right;
        }
        else{
            left.next=merge(right,left.next);
            return left;
        }

    }
}
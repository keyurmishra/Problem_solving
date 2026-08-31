class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next ||!head->next->next){
            return {-1,-1};
        }
        //let take the prev curr and nxt
        ListNode* prev=head;
        ListNode* curr=head->next;
        int firstcritical=-1;
        int prevcritical=-1;
        int min_dist=INT_MAX;
        int idx=1;
        // now check for the curr to be the critical point 
        while(curr->next){
            //maxima or minima value find out kro 
            if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val<prev->val && curr->val<curr->next->val)){
                if(firstcritical==-1){
                    firstcritical=idx;
                }
                else{
                    min_dist=min(min_dist,idx-prevcritical);

                }
                prevcritical=idx;



            }
            prev=curr;
            curr=curr->next;
            idx++;
        }
        if(firstcritical==-1 || firstcritical == prevcritical){
            return {-1,-1};
        }
        return {min_dist,prevcritical-firstcritical};
    }
};
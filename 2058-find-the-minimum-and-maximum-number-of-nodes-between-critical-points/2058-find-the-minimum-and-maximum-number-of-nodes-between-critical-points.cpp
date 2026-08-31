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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr=head->next;
        ListNode* prev=head;
        int cnt=0,firstind=0,ind=1,minD=INT_MAX,maxD=0,prevind=0;
        while(curr->next!=NULL){
            ListNode* nextcurr=curr->next;
            if((curr->val>nextcurr->val && curr->val > prev->val) || (curr->val < nextcurr->val && curr->val < prev->val)){
                cnt++;
                if(cnt==1){
                    firstind=ind;
                }
                else{
                    minD=min(minD,ind-prevind);
                }
                prevind=ind;
            }
            prev=curr;
            curr=nextcurr;
            ind++;
        }
        if(cnt>=2){
            return {minD,prevind-firstind};
        }
        return {-1,-1};
    }
};
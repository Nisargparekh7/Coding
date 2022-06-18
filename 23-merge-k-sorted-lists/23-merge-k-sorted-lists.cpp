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
    
    ListNode* merge(ListNode* a,ListNode*b ){
        if(!a)return b;
        if(!b)return a;
        ListNode* temp=NULL;
        if(a->val < b->val){
            temp=a;
            temp->next=merge(a->next,b);
            
        }
        else{
            temp=b;
            temp->next=merge(a,b->next);
        }
        return temp;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n= lists.size();
        
        if(n==0)return 0;
        if(n==1)return lists[0];
        
        ListNode* ans=NULL;
        for(auto l:lists){
            ans=merge(ans, l);
        }
        return ans;
    }
};
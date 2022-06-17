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
        
    ListNode* rotate(ListNode* head){
        ListNode * n=head;
        ListNode * m=head;
        ListNode * temp=head;
        
        if (head==NULL || head->next ==NULL) return head;
        while(m->next->next !=NULL){
            m = m->next;
        }
        n=m->next;
        
            n->next=temp;
            m->next =NULL;
            head=n;
        
        return head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
//         ListNode * n=head;
//         ListNode * m=head;
      ListNode * temp=head;
        
       if (head==NULL || head->next ==NULL) return head;
//         while(m->next->next !=NULL){
//             m = m->next;
//         }
//         n=m->next;
        
//             n->next=temp;
//             m->next =NULL;
//             head=n;
        int count=0;
        while(temp){
            count++;
            temp = temp->next;
        }
                // cout<<k<< "  ";  
                // cout<<count<< "  ";  
        int x= k % count;
        // cout<<x<< "  ";         
        // x=x-1;
        // cout<<x<<"  ";
        while(x>0) {
            cout<< "in" ;
            head= rotate(head);
            x--;
        }
        
        return head;
    }
};
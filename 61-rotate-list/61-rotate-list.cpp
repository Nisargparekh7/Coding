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

      ListNode * temp=head;
        
       if (head==NULL || head->next ==NULL) return head;
        int count=1;
        while (temp->next){
            ++count;
            temp=temp->next;
        }
        
        // linking last node to head
        temp->next=head;
        
        k= k% count;
        k= count-k;
        
        // tarvasal till k, and make  head=temp->next , and k->next=null 
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
       
        
        return head;
    }
};
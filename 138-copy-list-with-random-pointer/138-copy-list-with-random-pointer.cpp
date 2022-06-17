/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter=head;
        Node* front = head;
        
        //first round, making deep copy
        while(iter!=NULL){
            front= iter->next;
            
            Node* copy= new Node(iter->val);
            iter->next= copy;
            copy->next = front;
             iter = front;
        }
        
        // second round, for making random pointers
        
        iter=head;
        while(iter!=NULL){
           front= iter->next;
            
            if(iter->random!=NULL)
            {iter->next->random= iter->random->next;}
            iter=iter->next->next;
        }
        // third round, removing link of deep copy from orignal linklist
        
        iter = head;
        Node  * psedunode= new Node(0);
        Node *copy=psedunode;
        while(iter!=NULL){
            front= iter->next->next;
            
            psedunode->next=iter->next;
            iter->next=front;
            
            psedunode=psedunode->next;
            iter=front;
        }
        
        return copy->next;
        
    }
};
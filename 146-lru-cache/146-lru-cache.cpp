class LRUCache {
public:
    class node{
        public:
        int val;
        int key; 
        node * prev;
        node * next;
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int k;
    unordered_map<int, node*> m;
    
    void addnode(node* newnode){
        node* temp= head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    
    void deletenode(node * delnode){
        node *delprev= delnode->prev;
        node *delnext= delnode->next;
        delprev->next=delnext;
        delnext->prev= delprev;
    }
    
    LRUCache(int capacity) {
        k=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        
        if(m.find(key)!=m.end()){
            node* ansnode = m[key];
            int ans= ansnode->val;
            m.erase(key);
            deletenode(ansnode);
            addnode(ansnode);
            m[key]= head->next;
            return ans;
        }
        return -1;
    }
    
    
    
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *exist = m[key];
            m.erase(key);
            deletenode(exist);
        }
        
        if(m.size()==k){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
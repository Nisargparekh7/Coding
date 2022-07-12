class MyQueue {
public:
    stack<int> s1; stack<int> s2;
    MyQueue() {
       
    } 
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int k= s1.size();
        while(k!=1){
            s2.push(s1.top());
            s1.pop();
            k--;
        }
        int temp= s1.top();
        s1.pop();
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
            
    }
    
    int peek() {
        
        int k= s1.size();
        while(k!=1){
            s2.push(s1.top());
            s1.pop();
            k--;
        }
        int temp= s1.top();
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
        
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
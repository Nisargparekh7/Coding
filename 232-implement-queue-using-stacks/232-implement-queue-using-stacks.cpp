class MyQueue {
public:
    stack<int> s1; stack<int> s2;
    int temp;
    int cur;
    MyQueue() {
       
    } 
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int x= peek();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            cur= s2.top();
            //s2.pop();
        }
        else{
            cur= s2.top();
            //s2.pop();
        }
        return cur;
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
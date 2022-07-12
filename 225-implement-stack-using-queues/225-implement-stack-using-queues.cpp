class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int n = q1.size()-1;
        while(n--){
            int temp= q1.front();
            q1.pop();
            q1.push(temp);
        }
        
    }
    
    int pop() {
        int a= top();
        q1.pop();  
        return a;
    }
    
    int top() {
        int ans= q1.front();
        return ans;
    }
    
    bool empty() {
        if(q1.empty())return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
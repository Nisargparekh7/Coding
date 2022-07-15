class MinStack {
public:
     //queue<int> q1;
    vector<pair<int,int>> s;  
    MinStack() {
        
    }
    
    void push(int x) {
       if(s.empty()) s.push_back({x,x});
        else{
            s.push_back({x,min(s.back().second,x)});
        }
    }
    
    void pop(){
         s.pop_back();
    }
    
    int top() {
       int ans= s.back().first;
        return ans; 
    }
    
    int getMin() {
        return s.back().second;
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
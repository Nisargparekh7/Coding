class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       
        //stroring value in map 
        unordered_map <char,int> m;
        for(auto a: tasks){
            m[a]++;
        }
        
        priority_queue<int> pq;
        for(auto a: m){
            pq.push(a.second);
        }
        int result=0;
        
        while(!pq.empty()){
            int time=0;
            vector<int> temp;
            
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top() -1);
                    pq.pop();
                    time++;
                }
                
            }
             for(auto i:temp){
                 if(i) pq.push(i);
             }
            
                 result+= pq.empty()? time: n+1;
        }
        return result;
    }
};
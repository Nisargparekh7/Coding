class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> m;
       for(auto a: nums){
            m[a]++;    
        }
        
       priority_queue<pair<int,int>, vector<pair<int,int>>,  greater<pair<int,int>> > pq;
       vector<int> ans;
       
        for(auto i:m){
            if(pq.size()<k){
                pq.push(make_pair(i.second, i.first));
            }
            else{
                if(i.second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(i.second, i.first));        
                }
                
            }
                
        }
        
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
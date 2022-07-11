class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> m;
        
        for(auto a: nums){
            m[a]++;    
        }
        int n= m.size();
        
        priority_queue<pair<int,int>> pq;
        for(auto i : m){
            pq.push(make_pair(i.second, i.first));
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
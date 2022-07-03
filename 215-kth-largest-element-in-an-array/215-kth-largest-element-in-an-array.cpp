class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //priority_queue<pair<int, int>>pq;
        //pq.push({nums[0],0});
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push({nums[i],i});
            }
            else{
                // if(pq.top().first < nums[i]){
                //     pq.pop();
                    pq.push({nums[i],i});
                pq.pop();
            }
        }
        // while(k!=0){
        //     pq.pop();
        //     k--;
        // }
        int ans= pq.top().first;
        return ans;
    }
};
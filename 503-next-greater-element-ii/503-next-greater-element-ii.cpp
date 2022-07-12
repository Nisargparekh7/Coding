class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
//        
        map<int,int> m;
        stack<int> st;
        int n= nums.size();
        vector<int> ans(n);
        
        for(int i=2*n-1;i>=0;i--){
            
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            
            if(st.empty()) {
                ans[i%n] = -1;
            }
            
            else{
                ans[i%n] =st.top();
            }
            st.push(nums[i%n]);
        }
//         vector<int> ans;
        
//         for(auto i: nums){
//             ans.push_back(m[i]);
//         }
        return ans;
        
        
        
        //map<int,int> m;
//         stack<int> st;
//         int n= nums.size();
        
//         for(int i=0;i<=(2*n)-1;i++){
            
//             while(!st.empty() && st.top()<=nums[i%n]){
//                 st.pop();
//             }
            
//             if(st.empty()) {
//                 m[nums[i%n]]=-1;
//             }
            
//             else{
//                 m[nums[i%n]]=st.top();
//             }
//             st.push(nums[i%n]);
//         }
//         vector<int> ans;
        
//         for(auto i: nums){
//             ans.push_back(m[i]);
//         }
//         return ans;
    }
};
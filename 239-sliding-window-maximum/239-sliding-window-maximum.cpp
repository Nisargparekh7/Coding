class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            //removes element which are out of sliding windion and which were preseent before
            if(!dq.empty() && dq.front()==i-k)dq.pop_front();
            
            // storing elements in decesing order
            while(!dq.empty() && a[dq.back()]<= a[i])dq.pop_back();
            dq.push_back(i);
            // 
            if(i>=k-1)ans.push_back(a[dq.front()]);
        }
        return ans;
    }
};
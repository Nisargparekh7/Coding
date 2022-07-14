class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<int> st;
        
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) left[i]=0;
            else left[i]= st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) right[i]=n-1;
            else right[i]= st.top()-1;
            st.push(i);
        }
        
        int maxA=0;
        
        for(int i=0;i<n;i++){
            maxA= max(maxA, heights[i] * (right[i]- left[i] +1 ));
        }
        return maxA;
    }
};
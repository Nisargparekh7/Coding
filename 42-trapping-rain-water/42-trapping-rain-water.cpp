class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int count=0;
        vector<int> left;
        vector<int> right;
        int temp1=0;
        for (int i=0;i<n;i++){
            temp1=max(temp1, height[i]);
            // cout<<temp1;
            left.push_back(temp1);
        }
        
        int temp2=0;
        for (int i=n-1;i>=0;i--){
            
            temp2=max(temp2, height[i]);
            right.push_back(temp2);
        }
        
        
        
        reverse(right.begin(), right.end());
        for(int i=0; i<n;i++){
            // cout<<left[i]<<" ";
            // cout<<right[i]<<" ";
            int x= min(left[i],right[i]);
            //cout<<x<<" ";
            count+= x- height[i];
        }
        return count;
    }
};
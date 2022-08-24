class Solution {
public:
    int rob(vector<int>& num) {
//         vector<int> temp1,temp2;
//         int n=num.size();
        
//         for(int j=0;j<n;j++)
//         { 
//             if(j!=0)temp1.push_back(num[j]);
//             if(j!=n-1)temp2.push_back(num[j]);
//         }
//        // cout<<f(temp2)<<" ";
//         return max(f(temp1),f(temp2));
        return f(num);
    }
    
    int f(vector<int>& nums) {
	    // code here
        int n=nums.size();
        
        if(n==1)return nums[0];
	    
        int prev=nums[0];
        
	    int prev2=0;
        
	    for(int i=1;i<n;i++){
	        
            int take= nums[i];
	        if(i-2>=0)take+=prev2;
	        
            int nottake= prev;
	        
            int curr= max(take, nottake);
	        
            prev2=prev;
	        prev=curr;
	    }
	    return prev;
	}
};
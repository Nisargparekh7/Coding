class Solution {
public:
    
    bool check(string &s1, string &s2){
        if(s1.size()!=s2.size()+1)return false;
        
        int first_ptr=0; //point to s1
        int second_ptr=0; //point to s2
        
        while(first_ptr<s1.size()){
        
        if(s1[first_ptr]==s2[second_ptr]){
            first_ptr++;second_ptr++;
        }
        else first_ptr++;
        
    }
    if(first_ptr==s1.size() && second_ptr==s2.size())return true;
    return false;
}
    
    
    
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        //sorting nums base on the size of string, 3rd parameter is comparator(new way to discribe instead of making funciton)
        sort(nums.begin(), nums.end(),[=](string s1,string s2){
            return s1.size()<s2.size();
        });
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                
                if(check(nums[i],nums[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
                
            }
            
            if(dp[i]>maxi){
            maxi=dp[i];
            }
      
        }
        
       return maxi;
    }
    
    
};
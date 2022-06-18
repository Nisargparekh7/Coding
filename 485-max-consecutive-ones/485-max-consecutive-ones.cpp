class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int temp=0;
        int n= nums.size();
        for(int i=0; i<n;i++){
            
            if(nums[i]==1){
                temp++;
            }
            else{
                count=max(count,temp);
                temp=0;
            }
            
            // if(temp>count) count=temp; temp=1; 
        }
        return max(count,temp);
    }
};
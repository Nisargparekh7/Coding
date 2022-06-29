class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        
        int low=0; int high=n-1; int mid;
        while(low<=high){
            mid=low + (high-low)/2;
            if(mid==0 || mid==n-1) return nums[mid];
            // cout<<mid<<" ";
            if(mid%2==1){
                
                if(mid>1 && nums[mid]!=nums[mid-1] && mid<=high &&nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
                else if(mid<=high &&nums[mid]!=nums[mid+1]){
                    low=mid+1;
                }
                else high=mid-1;
            }    
            else {
                if(mid>1 && nums[mid]!=nums[mid-1] && mid<=high &&nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
                else if(mid>1 && nums[mid]==nums[mid-1]){
                    high=mid-1;
                }
                else low=mid+1;
            }
        }
        return nums[mid];
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        //int col=nums[0].size();
        
        int low=0, high=n-1, mid;
        while(low<=high){
            
            mid= low+(high-low)/2;
            
            if( nums[mid]== target)return mid;
            //if left side is sorted
            if(nums[low]<=nums[mid]){
                // then find elemrnt in that
                if(nums[low]<= target && target<= nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
            // else right side is sorted
            else{
                // then find elemrnt in that
                if(nums[mid]<= target && target<= nums[high]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        
        return -1;
    }
};
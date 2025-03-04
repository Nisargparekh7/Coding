class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int temp=-1;
        int temp_pos=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1] > nums[i]){
                temp = i;
                break;
            }
        }
        if(temp == -1 ){
            reverse(nums.begin(),nums.end());;
            return;
        }
        for(int i=n-1;i>temp;i--){
            if(nums[i] > nums[temp]){
                swap(nums[temp],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+temp+1,nums.end());
    return;

    }
};
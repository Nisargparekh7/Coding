class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int curElement = 0;
        int majorElement =0;
        int cnt=0;
        for (int i=0;i<n;i++){
            curElement = nums[i];
            if(cnt ==0){
                majorElement = curElement;
            }
            if(curElement == majorElement)cnt++;
            else{
                cnt--;
            }
        }
        return majorElement;
    }
};
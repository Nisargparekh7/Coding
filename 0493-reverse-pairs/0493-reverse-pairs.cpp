class Solution {
public:

    void merge(int low, int mid, int high, vector<int>& nums){
        int i= low;
        int j =mid+1;
        vector<int>temp;
        while(i<=mid && j<=high){
            if(nums[i]<= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
                temp.push_back(nums[i]);
                i++;
            }
        while(j<=high){
                temp.push_back(nums[j]);
                j++;
            }

        for(int i=low;i<=high;i++){
                nums[i] = temp[i-low];
            }
    }
int countpairs(vector<int>& nums, int low ,int mid ,int high)
    {   
        int right = mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i] > ( (int)2*(long long)nums[right]) )right++;
            cnt += (right-(mid+1));
        }
        return cnt;
    }

    int mergesort(int low, int high,  vector<int> &nums){
        if(low>=high)return 0;
        int mid = low + (high-low)/2;
        int ans=0;
        ans+=mergesort(low,mid, nums);
        ans+= mergesort(mid+1, high, nums);
        ans+= countpairs(nums,low, mid, high);
        merge(low, mid, high, nums);
        return ans;

    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();

        return mergesort(0,n-1,nums);

    }
};
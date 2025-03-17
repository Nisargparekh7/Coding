class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //sort(nums1.begin(), nums1.end());
        //sort(nums2.begin(), nums2.end());

        int i=m-1;
        int j=0;
        int temp =m;

        while(i>=0 && j < n ){
            if(nums2[j] < nums1[i]){
                swap(nums2[j], nums1[i]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());
        for(int i=0;i<n;i++){
            nums1[m+i] =nums2[i];
        }

       return; 


    }
};
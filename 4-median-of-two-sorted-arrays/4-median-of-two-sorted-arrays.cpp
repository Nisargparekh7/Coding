class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2= nums2.size();
        
        int l1 = INT_MIN;
        int l2= INT_MIN;
        
        int r1= INT_MAX;
        int r2= INT_MAX;
        
        //int ans=0;
        if(n1>n2) return(findMedianSortedArrays(nums2,nums1));
        int low=0, high=n1, cut1, cut2;
        
        while(low<=high){
            
            cut1= low+ (high-low)/2;
            cut2= (n1+ n2+1)/2 - cut1;
            
            
            l1= cut1==0? INT_MIN: nums1[cut1-1];
            l2= cut2==0? INT_MIN: nums2[cut2-1];
            
            r1=cut1==n1? INT_MAX: nums1[cut1];
            r2=cut2==n2? INT_MAX: nums2[cut2];
          
            if(l1>r2){
                high=cut1-1;
            }
            else if(r1<l2){
                low=cut1+1;
            }
            else{
                if( (n1+n2) %2 ==0){
                    return (max(l1,l2)+ min(r1,r2))/2.0;    
                }
                else return(max(l1,l2));
            }
        }
        return 0.0;
    }
};
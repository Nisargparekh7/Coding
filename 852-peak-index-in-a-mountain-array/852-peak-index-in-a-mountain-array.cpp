class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0,ans=0, high=n-1, mid;
        
        while(low<=high){
            mid= (low+high)/2;
            if(mid==0) low=mid+1;
            if(mid==n-1) high=mid-1;
            if(mid>=1 &&  mid+1<n){
                
                if(arr[mid-1]< arr[mid] && arr[mid] > arr[mid+1]){
                    return mid;
            }
            
            else if(arr[mid-1]< arr[mid] && arr[mid] <arr[mid+1] ){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
        return 0;
    }
};
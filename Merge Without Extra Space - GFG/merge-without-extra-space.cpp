//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long nums1[], long long nums2[], int n, int m) 
        { 
            // code here 
            // long long i=0,j=0;
            // int k=n-1;
            // while(i<=k && j<m){
            //     if(arr1[i]<arr2[j])i++;
            //     else if(arr1[i]>=arr2[j]){
            //         swap(arr1[k],arr2[j]);
            //         k--;
            //         j++;
            //     }
            // }
            
            // sort(arr1,arr1+n);
            // sort(arr2,arr2+m);
            
            int gap=ceil((float) (m+n)/2 );
        while(gap>0){
            int i=0;
            int j=gap;
            while(j<(m+n)){
                if(j<n && nums1[i]>nums1[j])swap(nums1[i],nums1[j]); 
                else if(j>=n && i<n && nums1[i]> nums2[j-n]) {
                    swap(nums1[i],nums2[j-n]);
                }
                else if (j>=n && i>=n && nums2[i-n]> nums2[j-n]){
                    swap(nums2[i-n],nums2[j-n]);;
                } 
                 i++;
                j++;
            }

            if(gap==1){
                gap=0;
            }
            else gap=ceil((float)gap/2);
        }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends
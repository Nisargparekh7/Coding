//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int nums[], int n) {
	    // code here
	    if(n==1)return 0;
	    int low=0, high=n-1;
	    int mid;
	    while(low<high){
	        mid=(low+high)/2;
	         if( (nums[mid]<nums[mid+1]) )low=mid+1;
	        else high=mid;
	    }
	    return nums[low];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
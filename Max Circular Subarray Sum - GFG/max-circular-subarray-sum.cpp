//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int nums[], int n){
        
        // your code here
        int max_Sum=INT_MIN;
        int min_Sum=INT_MAX;
        int array_Sum=0;
        int temp_maxSum=0;
        int temp_minSum=0;

        for(int i=0;i<n;i++){
            array_Sum+=nums[i];

            temp_maxSum+=nums[i];
            max_Sum=max(temp_maxSum,max_Sum);
            if(temp_maxSum<0)temp_maxSum=0;
            

            temp_minSum+=nums[i];
            min_Sum=min(min_Sum,temp_minSum);
            if(temp_minSum>0)temp_minSum=0;
            
        }
        if(array_Sum==min_Sum){
            //cout<<"hi";
            return max_Sum;
        }
        return max(max_Sum, array_Sum-min_Sum );
    }                                                                          
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
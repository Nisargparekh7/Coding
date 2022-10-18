//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    bool ispossible(int arr[], int n, int k, long long mid){
        long long cnt=1;
        long long sum=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]+sum<=mid)sum+=arr[i];
            else{
                cnt++;
                //cout<< cnt<<" ";
                if(cnt>k || arr[i]>mid)return false;
                
                sum=arr[i];
            }
        }
        // cout<<"sum is"<< sum << " ";
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long low=0,high=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        while(low<=high){
            long long mid= (low+high)/2;
            if(ispossible(arr,n,k,mid)){
                
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
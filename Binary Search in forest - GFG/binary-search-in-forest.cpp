//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        // code here 
        int low=0;int high;
        for(int i=0;i<n;i++){
            high+=tree[i];
        }
        
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            int sum=0;
            for(int i=0;i<n;i++ ){
                if(tree[i]-mid>0)sum+=tree[i]-mid;
            }
            if(sum==k)return mid;
            
            if(sum<k)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends
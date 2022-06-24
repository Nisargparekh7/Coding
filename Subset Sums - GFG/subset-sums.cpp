// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    //unordered_set<int> ans;
    
    void subset_sum(int index, vector<int>& arr, vector<int>& sum,int ans, int n){
        if(index==n) {
            sum.push_back(ans);
            return ;
        }
        
    //   sum.push_back(arr[index]);
    //   ans +=arr[index];
      //cout<< ans<< " ";
      
      subset_sum(index+1,arr,sum,ans+arr[index], n);
      
    //   sum.pop_back();
    //   ans -=arr[index];
      //cout<< ans<< " ";
      
      subset_sum(index+1,arr,sum,ans,n);
       
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sum;
        int ans;
        subset_sum(0,arr,sum,0,N);

        return sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> nums, long long x)
    {
        // code here
        pair<long,long>ans={-1,-1};
        long long n= nums.size();
        long long low =0, high = n-1;
        long long mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==x){
                int left=mid,right=mid;
                while(left-1>=0 && nums[left-1]==nums[mid])left--;
                while(right+1<n && nums[right+1]==nums[mid])right++;
                ans.first=left;
                ans.second=right;
                return ans;
            }
            if(nums[mid]>x)high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //helper function
    bool ispossible(int A[], int N, int M, int mid){
        int studentCount=1;
        int pageCount=0;
        for(int i=0;i<N;i++){
            if(pageCount+A[i]<=mid)pageCount+=A[i];
            else{
                studentCount++;
                if(studentCount >M || A[i]>mid)return false;
                //else starting pagecount for new partioion from that value
                pageCount=A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {   
        if(M>N)return -1;
        int low=0;
        int high=0;
        for(int i=0;i<N;i++){
            high+=A[i];
        }
        //cout<<high;
        int ans=-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(ispossible(A,N,M,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
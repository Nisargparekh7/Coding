// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    bool static comparator( Job a,  Job b){
        if(a.profit== b.profit) return (a.dead>b.dead);
        return (a.profit> b.profit);
    
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comparator);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }
        int a[maxi+1]={};
        for(int i=0;i<n;i++){
            
            int x= arr[i].dead;
            x=x-1;
            
                for(int k=x; k>=0;k-- ){
                    if(a[k]==0){
                        a[k]=arr[i].profit;
                        //cout<<arr[i].profit<<" ";
                        break;
                    }   
            }
        }
        
        
        int sum=0;
        int count=0;
        vector<int> ans(2,0);
        for(int j=0;j<maxi;j++){
            if(a[j]!=0){
                count ++;
                sum+=a[j];
            }
        }
        

         ans[0]=count;
        ans[1]=sum;
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
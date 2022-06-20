// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    struct platform{
        int arr;
        int dep;
        int pos;
    };
    
    bool static comparator(struct platform a, struct platform b){
        if(a.arr<b.arr && a.dep<b.dep  ) return true;
        // else if(a.arr>b.arr && ) return false;
        else if(a.pos<b.pos) return true;
        return false;
    }
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int , int>> t;
        for(int i=0;i<n;i++){
            t.push_back({arr[i],dep[i]});
        }
        sort(t.begin(),t.end());
        int count=1;
        
        vector<pair<int , int>> p;
        
        for(int i=0; i<n;i++){
            if(p.size()==0){
                p.push_back(t[i]);
            }
            else{
                int flag=0;
                for(int k=0;k<p.size();k++){
                    if(t[i].first> p[k].second){
                        p.erase(p.begin()+k);
                        p.push_back(t[i]);
                        flag=1;
                        break;
                    }
                    
                }
                if(flag==0){
                    p.push_back(t[i]); 
                    count++;
                }
            }
        }
        return count;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
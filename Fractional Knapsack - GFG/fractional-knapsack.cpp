// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(pair<double,int> p1,pair<double,int> p2){
        
        return p1.first > p2.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> a;
        
        for (int i=0;i<n;i++){
            
            double v=arr[i].value;
            double y=arr[i].weight;

            double x= (double)v/y;
            a.push_back({x,i});
        }
        sort(a.begin(),a.end(),comp); 
        //cout<<"----"<<a[0].second<<" "<<a[0].first<<endl;
        double sum=0;
        for(int i=0; i<n;i++){
            
            int temp=a[i].second;
            if(W< 0)break;
            
            if(arr[temp].weight<=W){
                sum+=arr[temp].value;
                //cout<< arr[temp].value<< " ";
                W-=arr[temp].weight;
                //cout<< W<< " ";
            }
            else{
                //cout<<"hi";
                sum += ((double)W/arr[temp].weight)*arr[temp].value;
                 W-=arr[temp].weight;
            }
        }
        return sum;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
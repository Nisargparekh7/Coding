class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int minp[k];
        int maxp[k];

        // if(k> n/2){
        // int maxprofit =0;
        // if (n==1) return 0;
        // for (int i=0;i<n-1;i++){
        //     if(prices[i]< prices[i+1]){
        //     maxprofit += prices[i+1]- prices[i];
        //     }
        // }
        // return maxprofit;
        // }


        for(int i=0;i<k;i++){
            minp[i] = INT_MAX;
            maxp[i] =0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                minp[j]= min(minp[j], prices[i]-(j>0?maxp[j-1]:0 )); 
                cout<<minp[j] <<"is minp" <<"\n";
                maxp[j]= max(maxp[j], prices[i]-minp[j]);
                cout<<maxp[j] << "is maxp" <<"\n";
            }
        }
        return maxp[k-1];
    }
};
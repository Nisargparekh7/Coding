class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min1 = INT_MAX, min2= INT_MAX;
        int p1=0, p2=0;
        for(int i=0;i<n;i++){
            min1= min(min1, prices[i]);
            p1 = max(p1,prices[i]-min1);

            min2 = min(min2, prices[i]-p1);
            p2= max(p2, prices[i]-min2);
        }
        return p2;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        bool flag =0;
        long nn =n;
        if(n<0){
            nn = -1* nn;
            flag =1;
        }
        while(nn>0){
            if(nn%2==1){
                ans*= x;
                nn=  nn-1;
            }
            else{
                x=x*x;
                nn= nn/2;
            }
        }
        if(flag) return (1/ans);
        return ans;
    }
};
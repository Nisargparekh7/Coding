class Solution {
public:
    double myPow(double x, int n) {
        double ans= 1;
        bool flag =0;
        long  i=n;
        if(n<0){
            i = (long)-1*n;
            flag=1;
        }

        while(i>0){
            printf("%d\n",i);
            if(i%2 == 0){
                x= x*x;
                i = i/2;
            }
            else{
                ans *= x;
                i = i-1;

            }
        }
        if(flag) return (1/ans);
        return ans;

    }
};
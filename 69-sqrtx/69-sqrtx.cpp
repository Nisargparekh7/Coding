class Solution {
public:
    int mySqrt(int x) {
        // time complexity O(n)
        // long long y=0;
        // while(y*y<=x){
        //     y++;
        // }
        // return y-1;
            
        //time complexity(logn) space O(1);
        long long s=0, e=x, mid,ans;
        while(s<=e){
            mid=(s+e)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid<x){
                s=mid+1;
                ans=mid;
            }
            else e= mid-1;
        }
        return ans;
    }
};
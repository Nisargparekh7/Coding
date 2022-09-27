class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        
        string ans="";
        // if any of numerator or denominator is -ve than add '-' to answer
        if(numerator >0 ^ denominator>0)ans+='-';
        
        long num=labs(numerator), den=labs(denominator);
        long q= num/den;
        long r= num% den;
        ans+=to_string(q);
        // perfectly divisible
        if(r==0)return ans;
        
        ans+='.';
        unordered_map<long,int>mp;
        
        while(r!=0){
            if(mp.find(r)!=mp.end()){
                int pos=mp[r];
                ans.insert(pos,"(");
                ans+=')';
                break;
            }
            else{
                mp[r]=ans.length();
                r*=10;
                q=r/den;
                r=r%den;
                ans+=to_string(q);
            }
        }
        return ans;
    }
};
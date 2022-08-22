class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        int index=0;
        string mapping[10] = {"","", "abc","def","ghi","jkl","mno", "pqrs","tuv", "wxyz"};
        
        if(digits.length()==0) return ans;
        solve(digits, index, output, ans, mapping);
        return ans;

    }
    void solve(string digits, int index, string output, vector<string> &ans, string mapping[]){
        
        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
         int number= digits[index] - '0';
        string s= mapping[number];
        
        for(int i=0; i<s.length();i++){
            output.push_back(s[i]);
            solve(digits, index+1, output, ans,mapping);
            output.pop_back();
        }
        
        
    }
};
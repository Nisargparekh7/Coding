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
    
    //function solve
    void solve(string digits, int index, string output, vector<string> &ans, string mapping[]){
        
        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        // convert number to string
        int number= digits[index] - '0';
        // find the mapping of the string. e.g 2-> "abc"
        string s= mapping[number];
        
        // running the  lopp for all the character. e.g a,b,c in "abc"
        for(int i=0; i<s.length();i++){
            //taken the element
            output.push_back(s[i]);
            //recursive call
            solve(digits, index+1, output, ans,mapping);
            //not taken the element and again for loop will run.
            output.pop_back();
        }
        
        
    }
};
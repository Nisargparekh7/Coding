class Solution {
public:
    vector<int>ncr(int n){
        vector<int> ans1;
        int temp = 1;
        ans1.push_back(1);
        for(int i=1;i<n;i++){
            temp *=n-i;
            temp /=i;
            ans1.push_back(temp);
        }
        return ans1;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=1;i<=numRows;i++){
            ans.push_back(ncr(i));
        }
        return ans;
    }
};
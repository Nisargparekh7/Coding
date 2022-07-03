class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        pair<int,char> block;
        pair<int,char> temp;
        pair<int,char> x;
        
        string ans="";
        
        for(auto a: s){
            m[a]++;
        }
        
        for(auto  &a :m){
            pq.push({a.second, a.first});
        }
        
        // temp[0]=pq.top();
        ans+=pq.top().second;
        x=pq.top();
        x.first--;
        block=x;
        pq.pop();
        
        while(pq.size()){
            temp=pq.top();
            pq.pop();
            ans+=temp.second;
            temp.first--;
            
            if(block.first > 0){
                pq.push(block);
            }
            block=temp;
        }
        // /if(block.first>0) return "";
        return ans.size()==s.size()? ans: "";
    }
};
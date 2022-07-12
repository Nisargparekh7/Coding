#include <bits/stdc++.h>
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1;
        
        stack<int> st2;
        
        for (int i=0;i<s.size();i++){
            if(isalpha(s[i]) ){
                st1.push(s[i]);
                //cout<<"isalpha "<<s[i]<<" ";
            }
            else if( st1.size() ){
                //cout<<"# "<<st1.top()<< " ";
                st1.pop();
            } 
        }
        
        
        for (int i=0;i<t.size();i++){
         if(isalpha(t[i]) ) {
             //cout<<"isalpha "<<t[i]<<" ";
                st2.push(t[i]);
            }
            else if(st2.size()) {
                st2.pop();
            }
        }
        
        
        if(st1.size()==st2.size()){
            while(st1.size()){
                int x1=st1.top(), x2=st2.top(); 
                //cout<< x1<<" "<< x2<<" ";
                if(x1!=x2) return 0;
                else {
                st1.pop();
                st2.pop();

                }
            }
            return true;
        }
        
        return false;
    }
};
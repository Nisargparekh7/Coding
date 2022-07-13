// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    stack<int> s1;
    vector<int> x;
    //int n=s.size();
while(s.size()){
    if(s1.empty()){
        s1.push(s.top());
       // cout<<s.top();
        s.pop();
    }
    else{
        while(s.size() && s1.size()&& s.top()<s1.top() ){
            x.push_back(s1.top());
            s1.pop();
        //s1.push(x);
        }
        s1.push(s.top());
        s.pop();
        
        for(int i=x.size()-1;i>=0;i--){
            s1.push(x[i]);
        }
        x.clear();
        //cout<< ""<< s.size();
    }
}
    s=s1;
   //Your code here
}
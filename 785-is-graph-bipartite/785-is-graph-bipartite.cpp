class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!check_BFS(i,graph,color))return false;
            }
        }
        return true;
    }
    
    
        //using DFS
       bool check_DFS(int node, vector<vector<int>>& graph , vector<int> color){
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    if(!check_BFS(it,graph,color))return false;
                }
                else if(color[it]==color[node])return false;
            }
        return true;
        } 
    
    //using BFS
     bool check_BFS(int src, vector<vector<int>>& graph , vector<int> color){
        
        queue<int>q;
        q.push(src);
        //intialize color with one, and later we use 1-color[src];
        color[src]=1;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: graph[node]){
                //if adj node is -1, color it and push it into queue
                if(color[it]==-1){
                    color[it]=1-color[node];
                   q.push(it);
                }
                //else if does color matches with node, return false
                else if(color[it]==color[node])return false;
            }
        }
        return true;
     }
    
    
    
    
    
    

};
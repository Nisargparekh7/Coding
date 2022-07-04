class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int d;
        int i;
        for(i=0;i<heights.size()-1;i++){
            
            if(heights[i]>heights[i+1]){
                 continue;       
            }
            
            d=heights[i+1]-heights[i];
            
            if(d<=bricks){
                    bricks-=d;
                    pq.push(d);
                }
            else if(ladders>0){
                if(pq.size()){
                    int x= pq.top();
                    if(x>d){
                        bricks+=x;
                        pq.pop();
                        pq.push(d);
                        bricks-=d;
                        }
                    }
                    ladders--;
                    
                }
                else break;
            }
            return i;             
        
    }
};
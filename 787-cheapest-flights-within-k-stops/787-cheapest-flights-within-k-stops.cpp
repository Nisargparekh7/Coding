class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
      map<int, vector<pair<int, int>>> graph;
        
        for (vector<int> flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];
            
            if (graph.find(u) == graph.end()) graph[u] = vector<pair<int, int>>();
            
            graph[u].push_back({v, p});
        }
        
        // { cost, node, stops }
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        vector<int> discovery(n + 1, INT_MAX); // To Avoid TLE
        
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            auto [cost, curr, stops] = top;
            
            if(stops > discovery[curr]) continue;  // To Avoid TLE
		    discovery[curr] = stops;
            
            if (curr == dst) return cost;
            
            if (stops > k) continue;
            
            for (auto it : graph[curr]) {
                auto [n, c] = it;
                
                pq.push({cost + c, n, stops + 1});
            }
        }
        
        return -1;
    }
};
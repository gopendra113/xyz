int dis(int x1,int y1,int x2,int y2) {
    return min(abs(x1 - x2) , abs(y1 - y2));
}

class Solution {
public:
    int minCostConnectPoints(vector<int>& x,vector<int>& y) {
        int n = x.size();
        vector<bool> visited(n, false);
        unordered_map<int, int> heap_dict;
        for(int i = 0; i < n; ++i) {
            heap_dict[i] = INT_MAX; // Initialize all distances to infinity
        }
        heap_dict[0] = 0; // Start node
        
        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
        min_heap.push({0, 0});
        
        int mst_weight = 0;
        
        while (!min_heap.empty()) {
            auto [w, u] = min_heap.top();
            min_heap.pop();
            
            if (visited[u] || heap_dict[u] < w) continue;
            
            visited[u] = true;
            mst_weight += w;
            
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int new_distance = dis(x[u],y[u],x[v],y[v]);
                    if (new_distance < heap_dict[v]) {
                        heap_dict[v] = new_distance;
                        min_heap.push({new_distance, v});
                    }
                }
            }
        }
        
        return mst_weight;
    }
};
// dijkstra with set
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList;
        adjList.resize(n);
        for(auto it: times){    // build adjacency list
            int u = it[0]-1;
            int v = it[1]-1;
            int times = it[2];
            adjList[u].push_back(make_pair(v, times));
        }
        
        // use set to approximate min-heap
        set<pair<int, int>> minHeap;
        // pair.first is the distance pair.second is the vertex
        minHeap.insert(make_pair(0, k-1));
        
        vector<int> dist;
        dist.resize(n, INT_MAX);
        dist[k-1] = 0;
        
        while(!minHeap.empty()){
            pair<int, int> curr = *(minHeap.begin());
            minHeap.erase(minHeap.begin());
            int u = curr.second;
            for(auto it: adjList[u]){
                int v = it.first;
                int times = it.second;
                if(dist[v] > dist[u] + times){
                    dist[v] = dist[u] + times;
                    minHeap.insert(make_pair(dist[v], v));
                }
            }
        }
        
        int ans = INT_MIN;
        for(auto it: dist){
            if(it == INT_MAX){
                return -1;
            }
            else if(it > ans){
                ans = it;
            }
        }
        
        return ans;
    }
};



// dijkstra with priority_queue
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList;
        adjList.resize(n);
        for(auto it: times){    // build adjacency list
            int u = it[0]-1;
            int v = it[1]-1;
            int times = it[2];
            adjList[u].push_back(make_pair(v, times));
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // pair.first is the distance pair.second is the vertex
        minHeap.push(make_pair(0, k-1));
        
        vector<int> dist;
        dist.resize(n, INT_MAX);
        dist[k-1] = 0;
        
        while(!minHeap.empty()){
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int u = curr.second;
            for(auto it: adjList[u]){
                int v = it.first;
                int times = it.second;
                if(dist[v] > dist[u] + times){
                    dist[v] = dist[u] + times;
                    minHeap.push(make_pair(dist[v], v));
                }
            }
        }
        
        int ans = INT_MIN;
        for(auto it: dist){
            if(it == INT_MAX){
                return -1;
            }
            else if(it > ans){
                ans = it;
            }
        }
        
        return ans;
    }
};
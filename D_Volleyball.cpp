#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Large value for infinity to prevent overflow issues
const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

// Standard Dijkstra function using C++11/C++14 syntax
void compute_road_distances(int src, int n, const vector<vector<Edge> >& road_adj, vector<long long>& dist) {
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    
    dist[src] = 0;
    pq.push(make_pair(0LL, src));
    
    while (!pq.empty()) {
        pair<long long, int> top_node = pq.top();
        pq.pop();
        
        long long d = top_node.first;
        int u = top_node.second;
        
        if (d > dist[u]) continue;
        
        for (size_t i = 0; i < road_adj[u].size(); ++i) {
            Edge edge = road_adj[u][i];
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push(make_pair(dist[edge.to], edge.to));
            }
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int start_node, end_node;
    cin >> start_node >> end_node;

    vector<vector<Edge> > road_adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        
        Edge edge1 = {v, w};
        Edge edge2 = {u, w};
        road_adj[u].push_back(edge1);
        road_adj[v].push_back(edge2); // Undirected roads
    }

    vector<long long> max_dist(n + 1);
    vector<long long> taxi_cost(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> max_dist[i] >> taxi_cost[i];
    }

    // Create an adjacency list for our transformed Taxi Graph
    vector<vector<Edge> > taxi_adj(n + 1);

    // Stage 1 & 2: Build the Taxi Graph
    vector<long long> dist(n + 1);
    for (int i = 1; i <= n; ++i) {
        compute_road_distances(i, n, road_adj, dist);
        
        for (int j = 1; j <= n; ++j) {
            if (i != j && dist[j] <= max_dist[i]) {
                Edge taxi_edge = {j, taxi_cost[i]};
                taxi_adj[i].push_back(taxi_edge);
            }
        }
    }

    // Stage 3: Find the minimum monetary cost from start_node to end_node
    vector<long long> min_cost(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

    min_cost[start_node] = 0;
    pq.push(make_pair(0LL, start_node));

    while (!pq.empty()) {
        pair<long long, int> top_node = pq.top();
        pq.pop();

        long long cost = top_node.first;
        int u = top_node.second;

        if (cost > min_cost[u]) continue;

        for (size_t i = 0; i < taxi_adj[u].size(); ++i) {
            Edge edge = taxi_adj[u][i];
            if (min_cost[u] + edge.weight < min_cost[edge.to]) {
                min_cost[edge.to] = min_cost[u] + edge.weight;
                pq.push(make_pair(min_cost[edge.to], edge.to));
            }
        }
    }

    // Output result
    if (min_cost[end_node] == INF) {
        cout << -1 << "\n";
    } else {
        cout << min_cost[end_node] << "\n";
    }

    return 0;
}
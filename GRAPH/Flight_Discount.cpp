#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define INF LLONG_MAX
 
void dijkstra(int start, vector<vector<pair<int, ll>>> &adj, vector<ll> &dist) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
 
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
 
        if (d > dist[node]) continue;  // Ignore outdated distances
 
        for (auto &[adjNode, weight] : adj[node]) {
            if (dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, ll>>> adj1(n + 1), adj2(n + 1);
    vector<ll> dis1(n + 1, INF), dis2(n + 1, INF);
 
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj1[u].push_back({v, w});  // Original graph
        adj2[v].push_back({u, w});  // Reversed graph
    }
 
    dijkstra(1, adj1, dis1);
    dijkstra(n, adj2, dis2);
 
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        for (auto &[v, w] : adj1[i]) {
            if (dis1[i] == INF || dis2[v] == INF) continue;
            ans = min(ans, dis1[i] + (w / 2) + dis2[v]);
        }
    }
 
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
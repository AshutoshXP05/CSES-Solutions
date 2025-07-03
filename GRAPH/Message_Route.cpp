#include <bits/stdc++.h>
using namespace std;

void dijkstra (vector<vector<int>> &adj, vector<int> &dist, vector<int> &parent) {
     queue<pair<int, int>> q;
     dist[1] = 0;
     q.push({1,0});

     while ( ! q.empty() ) {
        int dis = q.front().second;
        int node = q.front().first; 
        q.pop();
        dist[1] = 0;
         
        for ( auto it : adj[node]) {
            int adjNode = it;
            if ( dis + 1 < dist[adjNode]) {
                dist[adjNode] = dis + 1;
                q.push({ adjNode, dist[adjNode]});
                parent[adjNode] = node;
            }
        }
     }
}


void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}


// user input ----
void solve(){
     int n, m;
     cin >> n >> m;
     vector<vector<int>> adj(n+1);
     int u,v;
     for ( int i=1; i<=m; i++ ) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     vector<int> dist(n+1, INT_MAX);
     vector<int> parent(n+1);
     for ( int i=1; i<=n; i++ ) parent[i] = i;
     dijkstra(adj, dist, parent);

    //   for ( int i=1; i<=n; i++ ) cout << dist[i] << " " ;
    //   cout << endl;
    //   for ( int i=1; i<=n; i++ ) cout << parent[i] << " " ;
     if ( dist[n] == INT_MAX ) { cout << "IMPOSSIBLE" ; return;}
     vector<int> ans;
     int node = n;
     while ( node != parent[node]) {
         ans.push_back(node);
         node = parent[node];
     }
     ans.push_back(1);
     reverse(ans.begin(), ans.end());
//      for ( auto it : ans ) cout << it << " ";
//      cout << endl;
// }
// cout << endl;
cout << ans.size() << endl;
for ( int i=0; i<ans.size(); i++ ) cout << ans[i] << " " ;
      cout << endl;
    }
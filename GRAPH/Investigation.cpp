
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define MOD 1000000007

priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

 
int main () {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for ( ll i=0; i<m; i++ ) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    vector<ll> dist(n+1, 1e18);
    vector<ll> ways(n+1, 0);
    vector<ll> cntMin(n+1, 0);
    vector<ll> cntMax(n+1, 0);
    dist[1] = 0;
    ways[1] = 1;
    cntMin[1] = 1;
    cntMax[1] = 1;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    pq.push({0, 1});

     while ( ! pq.empty() ) {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        for ( auto it : adj[node] ) {
            ll adjNode = it.first;
            ll d = it.second;
            if ( dis + d < dist[adjNode] ) {
                dist[adjNode] = dis + d;
                ways[adjNode] = ways[node];
                // ways[adjNode] = ways[node];
                cntMin[adjNode] = cntMin[node] + 1;
                cntMax[adjNode] = cntMax[node]  + 1;
                pq.push({dist[adjNode], adjNode});
            }
            else if ( dis + d == dist[adjNode] ) {
                ways[adjNode] += ways[node];
                ways[adjNode] %= MOD;
                cntMin[adjNode] = min ( cntMin[adjNode], cntMin[node] + 1);
                cntMax[adjNode] = max ( cntMax[adjNode], cntMax[node] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << cntMin[n] - 1 << " " << cntMax[n] - 1 << endl;

}

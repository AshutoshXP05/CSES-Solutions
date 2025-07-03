#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

     vector<tuple<ll,ll,ll>> adj(m);
     for ( ll i=0; i<m; i++ ) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[i] = {a, b, c};
     }

     ll x;
     vector<ll> dist(n+1, 0);
     vector<ll> parent(n+1, -1);

     for ( ll i=1; i<=n; i++ ) {
         
          x = -1;
         for ( auto [u, v, w] : adj ) {
            if ( dist[u] + w < dist[v]  ) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
         }
        }

         if ( x == -1 ) {
            cout << "NO" << endl;
            // return;
         }

         else {

             for ( ll i=1; i<=n; i++ ) {
                 x = parent[x];
             }

             vector<ll> cycle;
             ll curr = x;
             cycle.push_back(curr);
             curr = parent[curr];

             while ( curr != x ) {
                cycle.push_back(curr);
                curr = parent[curr];
             }

             cycle.push_back(x);
             reverse(cycle.begin(), cycle.end());

             cout << "YES" << endl;
             for ( auto it : cycle ) cout << it << " " ;
             cout << endl;

         }

     }  


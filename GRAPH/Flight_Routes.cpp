#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k ;
    cin >> n >> m >> k ;

     vector<vector<pair<ll,ll>>> v(n+1);
     for (ll i=0; i<m; i++ ) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
     }
// pair<ll,ll>
     vector<vector<ll>> dist(n+1, vector<ll>(k, 1e18));

     priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

     dist[1][0] = 1;
     pq.push({0, 1});

     while ( ! pq.empty() ) {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if ( dist[node][k-1] < dis ) continue;

        for ( auto it : v[node] ) {
             ll adjNode = it.first;
             ll d = it.second;
             if ( dist[adjNode][k-1] > dis + d  ) {
                 dist[adjNode][k-1] = dis+d;
                 pq.push({dis+d, adjNode});
                 sort(dist[adjNode].begin(), dist[adjNode].end()) ;
             }
        }
     }

     for ( ll i=0; i<k; i++ ) {
         cout << dist[n][i] << " ";
     }
     cout << endl;

}  


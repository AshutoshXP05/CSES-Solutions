
#include <bits/stdc++.h>
using namespace std;
#define ll long long

    ll n, m;

void dfs( ll node, vector<ll> &parent, vector<ll> &vis, vector<ll> &dp, vector<vector<ll>> &adj ) {
    vis[node] = 1;

    for ( auto it : adj[node] ) {
        if ( ! vis[it] ) 
        dfs(it, parent, vis, dp, adj) ;

        if ( dp[it] != -1 && dp[it] + 1 > dp[node]  ) {
            dp[node] = dp[it] + 1;
            parent[node] = it;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<ll>> adj(n+1);
    for ( ll i=0; i<m; i++ ) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<ll> parent(n+1, -1);
    vector<ll> vis(n+1, 0);
    vector<ll> dp(n+1, -1);

    dp[n] = 1;

    dfs(1, parent, vis, dp, adj );

    if ( dp[1] == -1 ) { cout << "IMPOSSIBLE" << endl; return 0; }

    else {

        ll node = 1;
        vector<ll> ans;

         while (  node != n  ) {
            ans.push_back(node);
            if ( node == n ) break;
            node = parent[node];
         }
         ans.push_back(n);

         cout << ans.size() << endl;
         for ( auto it : ans ) {
            cout << it << " ";
         }
         cout << endl;

    }

}




/*
// DIKESTRA BUT IT WILL GIVE TLE 
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

     parent[1] = 1;
     dist[1] = 0; 
     pq.push({0, 1});

     while ( ! pq.empty() ) {
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        for ( auto it : adj[node] ) {
            if ( dis -1 < dist[it] ) {
                dist[it] =  dis -1 ;
                parent[it] = node;
                pq.push({dist[it], it});
            }
        }
     }
     ll endNode = n;

     if ( dist[endNode] == 1e18) { cout << "IMPOSSIBLE" << endl; return 0; } 

     ll startNode = 1;

     vector<ll> ans ;
     cout << (- dist[endNode]) + 1 << endl;
     while ( startNode != endNode ) {
        ans.push_back(endNode);
        endNode = parent[endNode];
     }
     ans.push_back(startNode);

     reverse(ans.begin(), ans.end());

    for ( auto it : ans ) cout << it << " ";
*/
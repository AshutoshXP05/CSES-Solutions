#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> dist(n + 1, 1e18);
    dist[1] = 0;

    vector<vector<ll>> adj(m);
    vector<vector<ll>> g(n + 1), rev(n + 1); // forward and reverse graphs

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[i] = {a, b, -c}; // negate weights for max path
        g[a].push_back(b);
        rev[b].push_back(a);
    }

    // Bellman-Ford Relaxation
    for (ll i = 1; i < n; i++) {
        for (auto it : adj) {
            if (dist[it[0]] != 1e18 && dist[it[0]] + it[2] < dist[it[1]]) {
                dist[it[1]] = dist[it[0]] + it[2];
            }
        }
    }

    // Detect nodes involved in negative cycle
    vector<ll> inCycle(n + 1, 0);
    for (auto it : adj) {
        if (dist[it[0]] != 1e18 && dist[it[0]] + it[2] < dist[it[1]]) {
            inCycle[it[1]] = 1;
        }
    }

    // DFS from 1 to mark reachable nodes
    vector<bool> reachable_from_1(n + 1, false);
    function<void(ll)> dfs1 = [&](ll u) {
        reachable_from_1[u] = true;
        for (ll v : g[u])
            if (!reachable_from_1[v])
                dfs1(v);
    };
    dfs1(1);

    // Reverse DFS from n to mark nodes that can reach n
    vector<bool> can_reach_n(n + 1, false);
    function<void(ll)> dfs2 = [&](ll u) {
        can_reach_n[u] = true;
        for (ll v : rev[u])
            if (!can_reach_n[v])
                dfs2(v);
    };
    dfs2(n);

    // Final check for negative cycle on path from 1 to n
    for (ll i = 1; i <= n; i++) {
        if (inCycle[i] && reachable_from_1[i] && can_reach_n[i]) {
            cout << -1 << endl;
            return;
        }
    }

    // Output maximum score (negated back)
    cout << -dist[n] << endl;
}

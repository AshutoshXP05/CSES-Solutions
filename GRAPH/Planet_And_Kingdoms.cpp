
// Application of Kosaraju's Algorithm --->

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve();
#define MOD 1000000007         // MODULUS 
#define PI 3.1415926535897932384626433832795
#define pb push_back       // PUSH _ BACK 
#define fi first         // FIRST 
#define se second    //SECOND 
#define endl '\n'      //  endl se fast hota hai isly we use /N 

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
#define yes cout<<"YES\n";              //  For yes 
#define no cout<<"NO\n";               // For No


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    // long long t;          // Test cases wala .. 
    // cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}

int n , m;
vector<int> vis;
stack<int> st;
vector<int> ans;
 int cnt = 0;


void dfs( int node, vector<vector<int>> &adj ) {
    vis[node] = 1;
    for ( auto it : adj[node] ) {
        if ( ! vis[it] ) {
            dfs(it, adj);
        }
    }
    st.push(node);
}

void dfs2( int node, vector<vector<int>> &adj ) {
    vis[node] = 1;
    ans[node] = cnt;
    for ( auto it : adj[node] ) {
        if ( ! vis[it] ) {
            dfs2(it, adj);
        }
    }
}


void solve() {
     cin >> n >> m;
     vector<vector<int>> adj(n+1);

     for ( int i=0; i<m; i++ ) {
        int a ,b ;
        cin >> a >> b;
        adj[a].pb(b);
     }

      vis.resize(n+1, 0);

      for ( int i=1; i<=n; i++ ) {
        if ( ! vis[i] ) {
            dfs(i, adj);
        }
      }

        vector<vector<int>> reverseAdj(n+1);

        for ( int i=1; i<=n; i++ ) {
            for ( int j=0; j<adj[i].size(); j++ ) {
                int val = adj[i][j] ;
                reverseAdj[val].pb(i);
            }
        }

        vis.assign(n+1, 0);
       

        ans.resize(n+1);

        while ( ! st.empty() ) {

            if ( ! vis[st.top() ]) {
                cnt ++;
                ans[st.top()] = cnt;
                dfs2(st.top(), reverseAdj) ;
            }

            st.pop();
        }

        cout << cnt << endl;
        for ( int i = 1; i<=n; i++ ) cout << ans[i] << " ";
        cout << endl;

}
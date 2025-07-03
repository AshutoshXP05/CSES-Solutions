#include <bits/stdc++.h>
using namespace std;


class Disjoint {
    public:
    vector<int> parent, size;
public:
     Disjoint(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for ( int i=1; i<=n; i++ )  {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findpar ( int u ) {
        if ( parent[u] == u ) return u ;
        return parent[u] = findpar(parent[u]);
    }

    void unionBysize ( int u, int v) {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if ( ulp_u == ulp_v ) return;

        if ( size[ulp_u] < size[ulp_v] ) {
             size[ulp_v] += size[ulp_u];
             parent[ulp_u] = parent[ulp_v];
        }
        else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = parent[ulp_u]; 
        }
    }
};


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
     Disjoint ds(n);
  
     int u, v;
     for ( int i=1; i<=m; i++ ) {
         cin >> u >> v;
   
         int upar = ds.findpar(u);
         int vpar = ds.findpar(v);
         ds.unionBysize(upar, vpar);
     }

     for ( int i=1; i<=n; i++ ) {
         ds.parent[i] = ds.findpar(i);
     }

     set<int> st;
     for ( int i=1; i<=n; i++ ) {
        st.insert(ds.parent[i]);
     }
     if ( st.size() == 1 ) { cout << 0 << endl; return;}
     cout << st.size() -1 << endl;
     auto it = st.begin();
    for (auto next_it = next(it); next_it != st.end(); ++it, ++next_it) {
        cout << *it << " " << *next_it << endl;
}
}
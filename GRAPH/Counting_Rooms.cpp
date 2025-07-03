
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int r, int c, int row, int col, vector<vector<char>> &adj, vector<vector<int>> &vis) {
    vis[r][c] = 1;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    for ( int i=0; i<4; i++ ) {
        int nrow = drow[i] + r;
        int ncol = dcol[i] + c;
        if ( nrow < row && ncol < col && nrow >= 0 && ncol >= 0 && ! vis[nrow][ncol] && adj[nrow][ncol] == '.' ) {
            dfs(nrow, ncol, row, col, adj, vis);
        }
    }

}


int main () {
    int n , m;
    cin >> n >> m;

    vector<vector<char>> adj(n, vector<char>(m));
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<m; j++ ) {
            cin >> adj[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int> (m, 0));
    int cnt = 0;

     for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<m; j++ ) {
            if ( adj[i][j] == '.' &&  ! vis[i][j] ) {
                dfs(i, j, n, m, adj, vis);
                cnt++;
            }
        }
     }

     cout << cnt << endl;

}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(int node, vector<int> &vis, vector<int> &parent, vector<int> &checkPath, vector<vector<int>> &adj, int &endNode, int &startNode)
{
    vis[node] = 1;
    checkPath[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            parent[it] = node;
            if (dfs(it, vis, parent, checkPath, adj, endNode, startNode))
                return true;
        }
        else if (checkPath[it] )
        {
            startNode = it;
            endNode = node;
            return true;
        }
    }
    checkPath[node] = 0;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> parent(n + 1, 0);
    vector<int> vis(n + 1, 0);
    vector<int> checkPath(n + 1, 0);
    int endNode = -1;
    int startNode = -1;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            parent[i] = i;
            if (dfs(i, vis, parent, checkPath, adj, endNode, startNode) == true)
            {
                break;
            }
        }
    }

    if (endNode == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    else
    {

        vector<int> ans;
        
        while (endNode != startNode )
        {
            ans.push_back(endNode);
            endNode = parent[endNode];
        }
        ans.push_back(endNode);
        reverse(ans.begin(), ans.end());
        ans.push_back(startNode);

        cout << ans.size() << endl;
        for (auto it : ans )  {
             cout << it << " " ;
        }
        cout << endl;
    }
}

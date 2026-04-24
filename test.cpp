#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn = 10005;
vector<int> adj[mn];
int val[mn];
int n;

int dfs(int u, int p, int ops, int tar) {
    int cur = (val[u] + ops) % 2;
    int res = 0;
    int num = ops;

    if (cur != tar) {
        res = 1;
        num = ops + 1;
    }

    for (int v : adj[u])
        if (v != p) 
            res += dfs(v, u, num, tar);

    return res;
}

void solve() {
    cin >> n;
    lin(i,1,n+1) adj[i].clear();
    
    lin(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    lin(i,1,n+1)
        cin >> val[i];

    int res0 = dfs(1, 0, 0, 0);
    int res1 = dfs(1, 0, 0, 1);
    
    cout << min(res0, res1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> p, rk;
ll res = 0;

ll get(int n) {
	return 1LL * n * (n - 1) / 2;
}

int getp(int n) {
	if (n == p[n]) return n;
	return p[n] = getp(p[n]);
}

void merge(int u, int v) {
	u = getp(u);
	v = getp(v);

	if (rk[u] < rk[v]) swap(u, v);

	res -= get(rk[u]);
	res -= get(rk[v]);

	rk[u] += rk[v];

	res += get(rk[u]);

	p[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	p = rk = vector<int>(n, 1);
	iota(p.begin(), p.end(), 0);

	vector<pair<int, pair<int, int>>> adj(n - 1);
	for (int i = 0; i < n-1; i++) {
		cin >> adj[i].second.first >> adj[i].second.second>>adj[i].first;

		adj[i].second.first--;
		adj[i].second.second--;
	}

	vector<pair<int, int>> q(m);
	for (int i = 0; i < m; i++) {
		cin >> q[i].first;
		q[i].second = i;
	}

	sort(q.begin(), q.end());
	sort(adj.begin(), adj.end());

	vector<ll> ans(m);
	int pos = 0;
	for (int i = 0; i < m; i++) {
		while (pos < n - 1 && adj[pos].first <= q[i].first) {
			int u = adj[pos].second.first;
			int v = adj[pos].second.second;

			merge(u, v);
			++pos;
		}

		ans[q[i].second] = res;
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}
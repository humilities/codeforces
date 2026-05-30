#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> pa;
vector<int> rk;
vector<int> sz;

int find(int v) {
  if (v == pa[v])
    return v;

  return pa[v] = find(pa[v]);
}

ll cnt(int x) {
  x = find(x);
  return (ll)sz[x] * (sz[x] - 1) / 2;
}

void init(int v) {
  pa[v] = v;
  sz[v] = 1;
  rk[v] = 0;
}

void un(int a, int b) {
  a = find(a);
  b = find(b);

  if (a != b) {
    if (rk[a] < rk[b])
      swap(a, b);

    pa[b] = a;
    if (rk[a] == rk[b])
      ++rk[a];

    sz[a] += sz[b];
  }
}

void solve() {
  int n;
  cin >> n;

  map<int, vector<int>> m;
  int num;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (i > 0)
      m[abs(a - num)].push_back(i);
    num = a;
  }

  pa.resize(n);
  rk.resize(n);
  sz.resize(n);

  for (int i = 0; i < n; i++)
    init(i);

  vector<ll> ans;
  ll curr = 0;

  for (int i = n - 1; i > 0; i--) {
    for (auto s : m[i]) {
      curr -= cnt(s);
      curr -= cnt(s - 1);

      un(s, s - 1);

      curr += cnt(s);
    }

    ans.push_back(curr);
  }

  reverse(ans.begin(), ans.end());
  for (auto x : ans)
    cout << x << ' ';

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

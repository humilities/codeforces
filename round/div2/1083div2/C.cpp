#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10, inf = ~0U >> 2;
int n, vis[MAXN];
vector<int> a[8010];
int chg[8010];

void init(vector<int> &now) {
  for (auto &v : now)
    cin >> v, vis[v] = 0;

  reverse(begin(now), end(now));
  vector<int> nw;

  for (auto v : now)
    if (!vis[v])
      nw.emplace_back(v), vis[v] = 1;
  for (auto v : nw)
    vis[v] = 0;

  now = nw;
}

void change(vector<int> &now) {
  if (now.size() == 1 && now[0] == inf)
    return;

  vector<int> nw;
  for (auto v : now)
    if (!vis[v])
      nw.emplace_back(v);

  now = nw;
}

void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int q = 0;
    cin >> q;

    a[i].resize(q);
    init(a[i]);
    chg[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    int id = 1;

    for (int j = 1; j <= n; j++) {
      if (!chg[j] && a[j] < a[id])
        id = j;
    }

    auto &now = a[id];
    for (auto v : now)
      cout << v << " ", vis[v] = 1;

    now = vector<int>{inf};
    chg[id] = 1;

    for (int j = 1; j <= n; j++) {
      if (!chg[j])
        change(a[j]);
    }
  }

  cout << "\n";
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

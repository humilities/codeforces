#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  lin(i, 0, n) cin >> a[i];

  vector<pair<ll, int>> can;
  ll curr = a[0];
  int dist = 0;

  while (curr > 1) {
    can.push_back({curr, dist++});
    if (curr % 2 == 0)
      curr /= 2;
    else
      curr++;
  }

  can.push_back({1, dist});
  if (a[0] == 1)
    can.push_back({2, 1});

  int k = can.size();
  vector<int> cnt(k, 0);
  vector<ll> csm(k, 0);

  for (int i = 0; i < n; i++) {
    ll val = a[i];
    map<ll, int> path;

    ll temp = val;
    int td = 0;

    while (temp > 1) {
      path[temp] = td++;
      if (temp % 2 == 0)
        temp /= 2;
      else
        temp++;
    }

    path[1] = td;
    if (val == 1)
      path[2] = 1;

    lin(j, 0, k) {
      if (path.count(can[j].first)) {
        cnt[j]++;
        csm[j] += path[can[j].first];
      }
    }
  }

  ll ans = -1;
  lin(j, 0, k) {
    if (cnt[j] == n) {
      if (ans == -1 || csm[j] < ans)
        ans = csm[j];
    }
  }
  cout << ans << "\n";
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

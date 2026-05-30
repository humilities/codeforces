#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  ll ans = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<vector<int>, ll> cnt;
  map<vector<int>, ll> base;

  for (int i = 0; i < n - 2; i++) {
    vector<int> b = {a[i], a[i + 1], a[i + 2]};

    vector<vector<int>> corr(3);
    corr[0] = {0, a[i + 1], a[i + 2]};
    corr[1] = {a[i], 0, a[i + 2]};
    corr[2] = {a[i], a[i + 1], 0};

    for (auto &pat : corr) {
      ans += cnt[pat] - base[b];

      cnt[pat]++;
    }

    base[b]++;
  }

  cout << ans << endl;
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  ll c, d;
  cin >> n >> c >> d;

  int total = n * n;
  vector<ll> b(total);
  map<ll, int> cnt;
  ll min_val = 2e9;

  for (int i = 0; i < total; i++) {
    cin >> b[i];
    cnt[b[i]]++;
    min_val = min(min_val, b[i]);
  }

  map<ll, int> expected;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll val = min_val + (ll)i * c + (ll)j * d;
      expected[val]++;
    }
  }

  if (cnt == expected) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
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

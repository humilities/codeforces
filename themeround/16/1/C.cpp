#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isp(ll x) { return (x & (x - 1)) == 0; }

void solve() {
  ll x;
  cin >> x;

  vector<ll> ans;
  ans.push_back(x);

  while (!isp(x)) {
    ll d = x & -x;
    x -= d;
    ans.push_back(x);
  }

  while (x > 1) {
    x /= 2;
    ans.push_back(x);
  }

  cout << ans.size() << "\n";
  for (ll v : ans)
    cout << v << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

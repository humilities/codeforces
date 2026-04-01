#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll div = a[0];
  for (int i = 1; i < n; i++) {
    if (gcd(div, a[i]) == 1) {
      cout << 1 << "\n";
      return;
    }

    div = gcd(div, a[i]);
    // cout << div << " ";
  }
  // cout << "\n";

  ll cnt = 0;
  for (ll i = 1; i <= (ll)sqrt(div); i++) {
    if (div % i == 0) {
      if (i * i == div)
        cnt++;
      else
        cnt += 2;
    }
  }

  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}

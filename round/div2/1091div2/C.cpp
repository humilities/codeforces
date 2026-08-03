#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
  ll n, m;
  cin >> n >> m;

  ll a, b;
  cin >> a >> b;

  if (gcd(a, n) != 1 || gcd(b, m) != 1) {
    cout << "NO" << "\n";
    return;
  }

  if (gcd(n, m) > 2) {
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
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

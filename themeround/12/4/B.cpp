#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

ll glcm(ll x, ll y) {
  ll mi = gcd(x, y);

  return x / mi * y;
}

void solve() {
  int a, b;
  cin >> a >> b;

  if (a == 1) {
    cout << b * b << "\n";
    return;
  }

  ll ret = glcm(a, b);
  if (ret == b)
    ret = b * (b / a);

  cout << ret << "\n";
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

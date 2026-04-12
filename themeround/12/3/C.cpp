#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll su(ll n) { return n * (n + 1) / 2; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll glcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void solve() {
  ll n;
  cin >> n;

  ll x, y;
  cin >> x >> y;

  ll lc = glcm(x, y);
  ll n1 = n / x - n / lc;
  ll n2 = n / y - n / lc;

  ll sum = su(n) - su(n - n1);
  ll di = su(n2);

  cout << sum - di << "\n";
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

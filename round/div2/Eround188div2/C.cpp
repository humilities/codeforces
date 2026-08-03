#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

ll slcm(ll x, ll y, ll m) {
  if (x > m || y > m)
    return m + 1;

  ll g = gcd(x, y);
  if ((x / g) > m / y)
    return m + 1;

  return (x / g) * y;
}

void solve() {
  int a, b, c;
  ll m;
  cin >> a >> b >> c >> m;

  ll tol = slcm(a, slcm(b, c, m), m);
  if (tol > m)
    tol = 0;
  else
    tol = m / tol;
  ll ab = slcm(a, b, m);
  if (ab > m)
    ab = 0;
  else
    ab = m / ab - tol;
  ll ac = slcm(a, c, m);
  if (ac > m)
    ac = 0;
  else
    ac = m / ac - tol;
  ll bc = slcm(b, c, m);
  if (bc > m)
    bc = 0;
  else
    bc = m / bc - tol;

  ll sa = m / a - tol - ab - ac;
  ll sb = m / b - tol - ab - bc;
  ll sc = m / c - tol - ac - bc;

  ll ansa = (ab + ac) * 3 + tol * 2 + sa * 6;
  ll ansb = (ab + bc) * 3 + tol * 2 + sb * 6;
  ll ansc = (bc + ac) * 3 + tol * 2 + sc * 6;

  cout << ansa << " " << ansb << " " << ansc << endl;
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

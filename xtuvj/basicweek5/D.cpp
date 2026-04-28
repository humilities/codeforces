// #include <bits/stdc++.h>
//
// #define lin(i, a, b) for (int i = (a); i < (b); i++)
// using namespace std;
// using ll = long long;
//
// const int mod = 1e9 + 7;
// const int mn = 200005;
// ll fac[mn], invfac[mn];
//
// ll powe(ll base, ll exp) {
//   ll res = 1;
//   base %= mod;
//
//   while (exp) {
//     if (exp & 1)
//       res = (res * base) % mod;
//     base = (base * base) % mod;
//     exp /= 2;
//   }
//
//   return res;
// }
//
// void pre() {
//   fac[0] = 1;
//   lin(i, 1, mn) fac[i] = (fac[i - 1] * i) % mod;
//
//   invfac[mn - 1] = powe(fac[mn - 1], mod - 2);
//   for (int i = mn - 2; i >= 0; i--)
//     invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
// }
//
// ll cn(ll n, ll k) {
//   if (k < 0 || k > n)
//     return 0;
//   return fac[n] * invfac[n - k] % mod;
// }
//
// void solve() {
//   int n;
//   cin >> n;
//
//   vector<int> a(n);
//   lin(i, 0, n) cin >> a[i];
//
//   vector<int> ma;
//   sort(a.begin(), a.end());
//
//   int cnt = 0;
//   lin(i, 1, n) {
//     if (a[i] == a[i - 1])
//       cnt++;
//     else
//       ma.push_back(cnt), cnt = 1;
//   }
//
//   ll ans = 0;
//   lin(i, 0, ma.size()) if (ma[i] >= 2) ans +=
//       (cn(ma[i], 2) * cn(n - 2, n - ma[i]) % mod);
//
//   cout << ans << "\n";
// }
//
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   pre();
//
//   int t;
//   cin >> t;
//
//   while (t--)
//     solve();
//
#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int mn = 200005;
ll fac[mn];

void pre() {
  fac[0] = 1;
  lin(i, 1, mn) fac[i] = (fac[i - 1] * i) % mod;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int tar = -1;

  lin(i, 0, n) {
    cin >> a[i];

    if (i == 0)
      tar = a[0];
    else
      tar &= a[i];
  }

  ll cnt = 0;
  lin(i, 0, n) if (a[i] == tar) cnt++;

  if (cnt < 2) {
    cout << 0 << "\n";
    return;
  }

  ll ans = cnt * (cnt - 1) % mod;
  cout << ans * fac[n - 2] % mod << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}

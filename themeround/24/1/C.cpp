// #include <bits/stdc++.h>
//
// using namespace std;
// using ll = long long;
//
// void solve() {
//   int n;
//   cin >> n;
//
//   vector<ll> a(n);
//   for (int i = 0; i < n; i++)
//     cin >> a[i];
//
//   vector<ll> suf(n + 1, 0);
//   for (int i = n - 1; i >= 0; i--)
//     suf[i] = suf[i + 1] + max((ll)0, a[i]);
//
//   ll ans = 0;
//   for (int i = 0; i < n; i++) {
//     ll num = ((i + 1) % 2 == 1 ? a[i] : 0) + suf[i + 1];
//
//     ans = max(ans, num);
//   }
//
//   cout << ans << "\n";
// }
//
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   int t;
//   cin >> t;
//
//   while (t--)
//     solve();
//
//   return 0;
// }

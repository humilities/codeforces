// #include <bits/stdc++.h>
//
// using namespace std;
// using ll = long long;
//
// void solve() {
//   int n;
//   cin >> n;
//
//   vector<int> a(n);
//   for (int i = 0; i < n; i++)
//     cin >> a[i];
//
//   sort(a.begin(), a.end());
//   a.erase(unique(a.begin(), a.end()), a.end());
//
//   vector<bool> ma(n, false);
//   for (int i = n - 1; i >= 0; i -= 2)
//     ma[i] = true;
//
//   map<int, int> th;
//   for (int i = 1; i < a.size(); i++)
//     th[a[i] - a[i - 1]]++;
//
//   int ans = 0;
//   for (auto [idx, val] : th) {
//     if (idx > n)
//       continue;
//     else if (ma[idx]) {
//       ans++;
//       ma[idx] = false;
//     }
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int l = 0;
  int ans = 0;

  for (int r = 0; r < a.size(); r++) {
    while (a[r] - a[l] > n - 1)
      l++;
    ans = max(ans, r - l + 1);
  }

  cout << ans << "\n";
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

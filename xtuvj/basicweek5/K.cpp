// #include <bits/stdc++.h>
//
// #define lin(i, a, b) for (int i = (a); i < (b); i++)
// using namespace std;
// using ll = long long;
//
// void solve() {
//   int n;
//   cin >> n;
//
//   vector<int> a(n);
//   vector<int> b(n);
//   lin(i, 0, n) cin >> a[i];
//   lin(i, 0, n) cin >> b[i];
//
//   unordered_map<int, int> mb;
//   lin(i, 0, n) mb[b[i]] = i;
//
//   // for (auto &[ba, val] : mb)
//   //   cout << "b[i]==" << ba << " " << "ma[b[i]]==" << val << "\n";
//   // cout << "\n";
//
//   int ans = 2e9;
//   lin(i, 0, n) {
//     int hi = a[i] + 1;
//
//     ans = min(ans, abs(i + mb[hi]));
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
//
#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> pos(2 * n + 5);
  lin(i, 0, n) {
    int a;
    cin >> a;

    pos[a] = i;
  }
  lin(i, 0, n) {
    int b;
    cin >> b;

    pos[b] = i;
  }

  vector<int> mn(2 * n + 5, 2e9);
  for (int i = 2 * n; i >= 2; i -= 2)
    mn[i] = min(mn[i + 2], pos[i]);

  int ans = 2e9;
  for (int i = 1; i <= 2 * n; i += 2)
    ans = min(ans, pos[i] + mn[i + 1]);

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

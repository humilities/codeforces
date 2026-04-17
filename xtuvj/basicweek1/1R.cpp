#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      cout << "NO" << endl;
      return;
    }

    int ne = (i + 1) % n;
    if (a[i] < b[i] && b[i] > b[ne] + 1) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  //
  // vector<ll> chu(n + 1);
  // for (int i = 0; i < n; i++)
  //   chu[i] = a[i];
  //
  // chu[n] = a[0];
  //
  // for (int i = n - 1; i >= 0; i--)
  //   if (chu[i] <= chu[i + 1])
  //     chu[i] = chu[i + 1] + 1;
  //
  // if (chu[n - 1] <= chu[n])
  //   chu[n - 1] = chu[0] + 1;
  //
  // for (int i = 0; i < n; i++) {
  //   if (chu[i] < b[i]) {
  //     cout << "NO" << "\n";
  //     return;
  //   }
  // }
  //
  // cout << "YES" << "\n";
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

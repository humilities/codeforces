#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  int cnt = 0;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    // cnt += a[i];
  }

  ll temp = 0;
  for (int i = 0; i < n; i++) {
    temp += a[i];

    // cout << temp << " ";

    if (temp <= 0) {
      cout << "NO" << endl;
      return;
    }
  }

  // cout << endl;

  temp = 0;
  for (int i = n - 1; i >= 0; i--) {
    temp += a[i];

    // cout << temp << " ";

    if (temp <= 0) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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

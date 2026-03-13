#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n), a(n);
  for (int &x : p)
    cin >> x;
  for (int &x : a)
    cin >> x;

  int pos = 0;
  for (int i = 0; i < n; i++) {
    while (pos < n && p[pos] != a[i]) {
      pos++;
    }

    if (pos == n) {
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int tot = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], tot ^= a[i];

  if (tot == 0) {
    cout << "YES" << "\n";
    return;
  }

  int cur = 0;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    cur ^= a[i];

    if (cur == tot) {
      cur = 0;
      cnt++;
    }
  }

  if (cnt >= 2)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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

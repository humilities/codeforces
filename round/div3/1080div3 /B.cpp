#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 5);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i += 2) {
    for (int j = i; j <= n; j *= 2) {
      for (int k = i * 2; k <= n; k *= 2) {
        if (a[k / 2] > a[k])
          swap(a[k / 2], a[k]);
      }
    }
  }

  for (int i = 1; i < n; i++) {
    if (a[i] != i) {
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

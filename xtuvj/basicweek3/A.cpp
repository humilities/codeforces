#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int mn = 15;

  for (int k = 0; k < n; k++) {

    for (int i = 0; i <= 15; i++) {
      for (int j = 0; j <= 15; j++)
        if (((a[k] + i) << j) % 32768 == 0)
          mn = min(mn, i + j);
    }

    cout << mn << " ";
    mn = 15;
  }

  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}

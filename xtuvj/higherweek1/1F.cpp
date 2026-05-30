#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> x(n);
  vector<int> h(n);

  for (int i = 0; i < n; i++)
    cin >> x[i] >> h[i];

  int ans = 0;
  int las = -1e9;
  for (int i = 0; i < n; i++) {
    if (x[i] - h[i] > las) {
      las = x[i];
      ans++;
    } else if (i == n - 1 || x[i] + h[i] < x[i + 1]) {
      las = x[i] + h[i];
      ans++;
    } else {
      las = x[i];
    }
  }

  cout << ans << endl;
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  int mx = -1, mn = 2e9;
  for (int i = 0; i < n; i++) {
    if (a[i] < mn)
      mn = a[i];
    if (a[i] > mx)
      mx = a[i];
  }

  vector<int> ans;
  while (mx != mn) {
    int x = (mn % 2 == 0) ? 0 : 1;
    ans.push_back(x);

    mx = (mx + x) / 2;
    mn = (mn + x) / 2;
  }

  if (ans.size() > n) {
    cout << ans.size() << "\n";
    return;
  }

  cout << ans.size() << "\n";
  for (int val : ans)
    cout << val << " ";

  cout << "\n";
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

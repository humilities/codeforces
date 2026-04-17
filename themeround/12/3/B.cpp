#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  vector<int> b;
  lin(i, 1, n) b.push_back(a[i] - a[i - 1]);

  int ans = 0;
  int l = 0;
  int temp = 0;
  lin(r, 0, b.size()) {
    temp += b[r];

    if (temp > 1) {
      l = r;

      temp = 0;
      ans++;

      // cout << l << "\n";
    }

    // cout << temp << " " << r << "\n";
  }

  cout << ans + 1 << "\n";
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

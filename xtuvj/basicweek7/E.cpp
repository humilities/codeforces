#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  int sm = -1;
  lin(i, 0, n) if (a[i] == n) {
    sm = i;
    break;
  }

  if (sm == 0) {
    lin(i, 0, n) {
      if (a[i] == n - 1) {
        sm = i;
        break;
      }
    }
  }

  int r = sm - 1;
  if (sm == n - 1)
    r = n - 1;

  vector<int> ans;
  lin(l, 0, r + 1) {
    vector<int> cur;

    lin(j, r + 1, n) cur.push_back(a[j]);
    for (int j = r; j >= l; j--)
      cur.push_back(a[j]);
    lin(j, 0, l) cur.push_back(a[j]);

    if (cur > ans)
      ans = cur;
  }

  lin(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
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

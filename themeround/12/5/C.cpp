#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  vector<int> cnt(2 * n + 1, 0);
  lin(i, 0, n) {
    cin >> a[i].first >> a[i].second;
    if (a[i].first == a[i].second)
      cnt[a[i].first]++;
  }

  vector<int> pre(2 * n + 1, 0);
  lin(i, 1, 2 * n + 1) pre[i] = pre[i - 1] + (cnt[i] > 0 ? 1 : 0);

  string ans = "";
  lin(i, 0, n) {
    int l = a[i].first;
    int r = a[i].second;

    if (l == r) {
      if (cnt[l] == 1)
        ans += '1';
      else
        ans += '0';
    } else {
      int num = pre[r] - pre[l - 1];
      int len = r - l + 1;

      if (num < len)
        ans += '1';
      else
        ans += '0';
    }
  }

  cout << ans << "\n";
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

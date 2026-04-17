#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<long long> suf(n);
  long long cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur = max({(long long)a[i], (long long)b[i], cur});
    suf[i] = cur;
  }

  vector<long long> pre(n + 1);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + suf[i];
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    if (i != q - 1)
      cout << (pre[r] - pre[l - 1]) << ' ';
    else
      cout << pre[r] - pre[l - 1] << "\n";
  }

  return;
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

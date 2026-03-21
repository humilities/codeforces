#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<ll> pre(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i - 1];
  }

  vector<int> cnt(n + 1);
  cnt[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] == 1) {
      cnt[i] = cnt[i - 1] + 1;
    } else
      cnt[i] = cnt[i - 1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    l--, r--;

    if (l == r) {
      cout << "NO" << endl;
      continue;
    }

    ll sum = pre[r + 1] - pre[l];
    int tol = cnt[r + 1] - cnt[l];
    ll len = r - l + 1;

    // int temp = tol * 2;

    // cout << tol << " " << len << endl;

    if (tol + len > sum) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
  }
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

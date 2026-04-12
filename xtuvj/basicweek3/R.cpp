#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  lin(i, 1, n + 1) cin >> a[i];

  vector<vector<int>> cnt(n + 1, vector<int>(31, 0));
  lin(j, 1, n + 1) lin(i, 0, 31) cnt[j][i] = cnt[j - 1][i] + ((a[j] >> i) & 1);

  int q;
  cin >> q;

  while (q--) {
    int l, k;
    cin >> l >> k;

    if (a[l] < k) {
      cout << -1 << " ";
      continue;
    }

    int lti = l;
    int r = n;
    int ans = -1;
    while (lti <= r) {
      int mid = lti + (r - lti) / 2;

      int cur = 0;
      lin(i, 0, 31) if (cnt[mid][i] - cnt[l - 1][i] == mid - l + 1) cur |= 1
                                                                           << i;

      if (cur < k)
        r = mid - 1;
      else
        ans = mid, lti = mid + 1;
    }

    cout << ans << " ";
  }

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

#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

bool che(ll mid, int n, int k, const vector<int> &t) {
  int seg = 0;
  ll curs = 0;
  int curm = 0;

  lin(i, 0, n) {
    if (t[i] > mid)
      return false;

    ll nexs = curs + t[i];
    int nexm = max(curm, t[i]);

    if (nexs - nexm > mid) {
      seg++;

      curs = t[i];
      curm = t[i];
    } else {
      curs = nexs;
      curm = nexm;
    }
  }

  seg++;
  return seg <= k;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> t(n);
  lin(i, 0, n) cin >> t[i];

  ll l = 0;
  ll r = 0;
  lin(i, 0, n) r += t[i];

  ll ans = 0;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (che(mid, n, k, t)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}

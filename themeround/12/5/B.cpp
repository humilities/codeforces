#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

bool che(ll w, ll n, ll k, vector<ll> &a) {
  ll co = 0;

  lin(i, 0, n) {
    if (a[i] < w) {
      co += w - a[i];
      if (co > k)
        return false;
    }
  }

  return co <= k;
}

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  ll mn = 0;
  vector<ll> a(n);
  lin(i, 0, n) cin >> a[i], mn = max(mn, a[i]);

  ll l = 1, r = mn + k;
  ll w = 1;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (che(mid, n, k, a)) {
      l = mid + 1;
      w = mid;
    } else
      r = mid - 1;
  }

  ll kre = k;
  lin(i, 0, n) if (a[i] < w) kre -= (w - a[i]);

  ll cnt = 0;
  lin(i, 0, n) if (max(a[i], w) == w) cnt++;

  cnt -= min(kre, cnt);
  cout << n * w - cnt + 1 << "\n";
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<ll> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  bool poss = true;
  for (int i = 1; i < n; i++) {
    if (c[i] < c[i - 1])
      poss = false;
  }

  if (!poss) {
    cout << "No\n";
    return;
  }

  vector<ll> b(n);
  int l = 0;

  while (l < n) {
    int r = l;
    while (r + 1 < n && s[r + 1] == '1')
      r++;

    vector<ll> del(r - l + 1, 0);
    for (int k = l + 1; k <= r; k++)
      del[k - l] = del[k - 1 - l] + a[k];

    bool has = false;
    ll req = 0;
    ll mn = 4e18;

    for (int k = l; k <= r; k++) {
      ll lim = c[k] - del[k - l];
      mn = min(mn, lim);

      if (k == 0 || c[k] > c[k - 1]) {
        if (has && req != lim) {
          poss = false;
          break;
        }
        has = true;
        req = lim;
      }
    }

    if (!poss)
      break;

    ll x;
    if (has) {
      if (req > mn) {
        poss = false;
        break;
      }
      x = req;
    } else {
      x = mn;
    }

    for (int k = l; k <= r; k++)
      b[k] = x + del[k - l];

    l = r + 1;
  }

  if (!poss) {
    cout << "No\n";
    return;
  }

  vector<ll> ans_a(n);
  ans_a[0] = b[0];
  for (int i = 1; i < n; i++)
    ans_a[i] = b[i] - b[i - 1];

  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && ans_a[i] != a[i])
      poss = false;
  }

  if (!poss) {
    cout << "No\n";
    return;
  }

  ll curb = ans_a[0];
  ll curc = ans_a[0];
  if (curc != c[0])
    poss = false;

  for (int i = 1; i < n; i++) {
    curb += ans_a[i];
    curc = max(curc, curb);
    if (curc != c[i])
      poss = false;
  }

  if (poss) {
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
      cout << ans_a[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
  } else {
    cout << "No\n";
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k, l, r;
  cin >> n >> k >> l >> r;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<int, int> cntl, cntr;
  int L = 0, R = 0;

  int difl = 0, difr = 0;
  ll tot = 0;
  for (int c = 0; c < n; c++) {
    cntl[a[c]]++;
    if (cntl[a[c]] == 1)
      difl++;
    while (difl > k) {
      cntl[a[L]]--;
      if (cntl[a[L]] == 0)
        difl--;
      L++;
    }

    cntr[a[c]]++;
    if (cntr[a[c]] == 1)
      difr++;
    while (difr > (k - 1)) {
      cntr[a[R]]--;
      if (cntr[a[R]] == 0)
        difr--;
      R++;
    }

    if (difl == k) {
      int thl = L;
      int thr = R - 1;

      int sel = c - r + 1;
      int ser = c - l + 1;

      int sta = max(thl, sel);
      int end = min(thr, ser);

      if (sta <= end)
        tot += (end - sta + 1);
    }
  }

  cout << tot << "\n";
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

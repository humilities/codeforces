#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int l, r;
  cin >> l >> r;

  vector<int> ans(r + 1, 0);
  ll sum = 0;
  ll curr = r;

  while (curr > 0) {
    ll mask = 1;
    while (mask < curr)
      mask = (mask << 1) | 1;

    ll l = mask - curr;
    ll le = l, rr = curr;

    while (le <= rr) {
      ans[le] = rr;
      ans[rr] = le;

      if (le == rr)
        sum += (le | rr);
      else
        sum += (le | rr) * 2;

      le++;
      rr--;
    }

    curr = l - 1;
  }

  cout << sum << "\n";
  for (int i = 0; i <= r; i++)
    cout << ans[i] << " \n"[i == r];
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(ll n, ll tar) {
  ll sum = n * (n - 1) / 2;

  if (sum <= tar)
    return true;
  else
    return false;
}

void solve() {
  ll n;
  cin >> n;

  ll l = 1, r = 2e9;
  ll mi = 0;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    // cout << mid << " ";

    if (check(mid, n))
      l = mid + 1, mi = mid;
    else
      r = mid - 1;
  }

  // cout << "\n";

  ll rem = mi * (mi - 1) / 2;
  ll ned = n - rem;

  cout << mi + ned << "\n";
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

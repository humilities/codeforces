#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int len(ll n) {
  int cnt = 0;
  while (n) {
    n /= 10;
    cnt++;
  }

  return cnt;
}

ll f(ll n) {
  ll ans = 0;
  while (n)
    ans = ans * 10 + n % 10, n /= 10;

  return ans;
}

void solve() {
  ll n;
  cin >> n;

  int leg = len(n);
  ll ans = 9e18;

  for (int i = 0; i <= leg; i++) {
    ll pos = pow(10, (ll)i);
    ll rem = n - (n % pos) + pos;

    if (rem % 10 == 0)
      rem += 1;
    ans = min(ans, f(rem));
  }

  cout << ans - 1 << "\n";
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

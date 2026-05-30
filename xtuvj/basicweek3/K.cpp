#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  // int msb = 0;
  // for (int i = 63; i >= 0; i--)
  //   if (n & (1LL << i)) {
  //     msb = i;
  //     break;
  //   }

  vector<ll> ans;
  for (int i = 0; i < 64; i++) {
    if ((n >> i) & 1) {
      // if (i == msb)
      //   continue;

      ll num = n ^ (1LL << i);
      if (num > 0)
        ans.push_back(num);
    }
  }

  ans.push_back(n);
  sort(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for (ll i = 0; i < ans.size(); i++)
    cout << ans[i] << " \n"[i == ans.size() - 1];
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

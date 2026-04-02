#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  ll temp = n;
  vector<pair<int, int>> ma;
  for (ll i = 2; i * i <= temp; i++) {
    if (temp % i == 0) {
      int cnt = 0;

      while (temp % i == 0) {
        cnt++;
        temp /= i;
      }
      ma.push_back({cnt, i});
    }
  }

  if (temp > 1)
    ma.push_back({1, temp});

  sort(ma.begin(), ma.end(), greater<>());
  pair<int, int> chu = ma.front();

  ll ct = chu.first;
  ll num = chu.second;

  cout << ct << "\n";
  vector<ll> ans(ct, num);

  ll res = 1;
  for (int i = 0; i < ct - 1; i++)
    res *= num;

  ans[ct - 1] = n / res;

  for (int i = 0; i < ct; i++)
    cout << ans[i] << " \n"[i == ct - 1];
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

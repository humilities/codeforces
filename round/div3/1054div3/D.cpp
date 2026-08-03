#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get(vector<int> &a) {
  int m = a.size();
  if (m == 0)
    return 0;

  vector<ll> tra;
  for (int i = 0; i < m; i++)
    tra.push_back((ll)a[i] - i);

  ll mid = tra[m / 2];
  ll cnt = 0;

  for (ll val : tra)
    cnt += abs(val - mid);

  return cnt;
}

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> posa, posb;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      posa.push_back(i);
    if (s[i] == 'b')
      posb.push_back(i);
  }

  ll ans = 0;
  ans = min(get(posa), get(posb));

  cout << ans << endl;
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

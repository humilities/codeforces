#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

vector<int> mul(const vector<int> &a, ll b) {
  vector<int> ret;
  ll ca = 0;

  lin(i, 0, a.size()) {
    ca += a[i] * b;

    ret.push_back(ca % 10);
    ca /= 10;
  }
  while (ca) {
    ret.push_back(ca % 10);
    ca /= 10;
  }

  while (ret.size() > 1 && ret.back() == 0)
    ret.pop_back();
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> ans = {1};
  lin(i, 1, n + 1) ans = mul(ans, i);
  lin(i, 1, m + 1) ans = mul(ans, i);
  lin(i, n - m + 2, n + 2) ans = mul(ans, i);

  ans = mul(ans, n + m + 1);
  ans = mul(ans, n + m);

  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}

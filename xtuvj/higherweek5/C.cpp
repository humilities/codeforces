#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

vector<int> mul(const vector<int> &a, ll b) {
  vector<int> ret;
  ll ca = 0;
  lin(i, 0, (int)a.size()) {
    ca += (ll)a[i] * b;
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

  lin(i, 1, n + 2) ans = mul(ans, i);
  ans = mul(ans, (ll)n * n + 3 * n + 2 * m);
  lin(i, n - m + 4, n + 3) ans = mul(ans, i);

  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

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

vector<int> sub(const vector<int> &a, const vector<int> &b) {
  vector<int> ret;
  int bor = 0;

  lin(i, 0, (int)a.size()) {
    int d = a[i] - bor - (i < (int)b.size() ? b[i] : 0);
    if (d < 0) {
      d += 10;
      bor = 1;
    } else
      bor = 0;
    ret.push_back(d);
  }

  while (ret.size() > 1 && ret.back() == 0)
    ret.pop_back();
  return ret;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> p1 = {1};
  lin(i, 1, n + 3) p1 = mul(p1, i);
  lin(i, n + 4 - m, n + 4) p1 = mul(p1, i);

  vector<int> p2 = {1};
  p2 = mul(p2, 2);
  lin(i, 1, n + 2) p2 = mul(p2, i);
  lin(i, n + 3 - m, n + 3) p2 = mul(p2, i);

  vector<int> ans = sub(p1, p2);
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

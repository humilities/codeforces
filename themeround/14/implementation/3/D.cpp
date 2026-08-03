#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> c(m + 1);
  ll cnt1 = 0;
  lin(i, 1, m + 1) cin >> c[i], cnt1 += c[i];

  vector<ll> q(m + 1);
  ll cnt2 = 0;
  lin(i, 1, n + 1) {
    int u, v;
    cin >> u >> v;

    q[v] += u;
    cnt2 += u;
  }

  if (cnt2 > cnt1) {
    cout << "NO" << "\n";
    return;
  }

  lin(i, 1, m + 1) {
    if (q[i] > cnt1 - c[i]) {
      cout << "NO" << "\n";
      return;
    }
  }

  cout << "YES" << "\n";
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

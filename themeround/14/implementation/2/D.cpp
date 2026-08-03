#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> b(n);
  lin(i, 0, n) cin >> b[i];

  int cur = n - 1;
  int step = min(n, k);
  bool flag = true;

  for (int i = 0; i < step; i++) {
    int dis = b[cur];

    if (dis > n) {
      flag = false;
      break;
    }

    cur = (cur - dis + n) % n;
  }

  if (flag)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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

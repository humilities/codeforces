#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  if (!(cin >> n))
    return;

  vector<int> p(n);
  vector<int> pos(n + 1);

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    pos[p[i]] = i;
  }

  for (int i = 0; i < n; ++i) {
    int target_val = n - i;

    if (p[i] != target_val) {
      int r = pos[target_val];
      reverse(p.begin() + i, p.begin() + r + 1);
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << p[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}

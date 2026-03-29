#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m, s, c;
  cin >> m >> s >> c;

  if (m >= c) {
    int val = 0;
    for (int i = 0; i < c; i++)
      cin >> val;
    cout << c << endl;
    return;
  }

  vector<int> pos(c);
  for (int i = 0; i < c; i++)
    cin >> pos[i];

  sort(pos.begin(), pos.end());

  int tol = pos[c - 1] - pos[0] + 1;
  vector<int> gap;

  for (int i = 1; i < c; i++) {
    int val = pos[i] - pos[i - 1] - 1;

    if (val)
      gap.push_back(val);
  }

  sort(gap.begin(), gap.end(), greater<>());

  for (int i = 0; i < min((int)gap.size(), m - 1); i++)
    tol -= gap[i];

  cout << tol << endl;
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

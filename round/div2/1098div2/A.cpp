#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  map<int, int> ma;

  vector<int> w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];

  for (int i = 0; i < n; i++)
    ma[w[i]]++;

  int c1 = min(ma[1], ma[2]);
  ma[1] -= c1;
  ma[2] -= c1;

  if (ma[1] && ma[1] >= 3)
    c1 += ma[1] / 3;

  if (ma[2] && ma[2] >= 3)
    c1 += ma[2] / 3;

  cout << c1 + ma[0] << "\n";
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

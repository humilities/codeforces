#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  map<int, int> ma;
  lin(i, 0, n) ma[a[i]]++;

  int c1 = 0;
  int c2 = 0;

  for (auto [node, val] : ma) {
    if (val == 1)
      c1++;
    else
      c2++;
  }

  cout << c2 + ceil((double((double)c1 / 2))) << "\n";
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

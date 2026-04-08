#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  int pos = 0;
  cin >> pos;

  pos--;
  int l = 0, r = 0;

  for (int i = 0; i < pos; i++)
    if (a[i] != a[pos] && a[i] != a[i + 1])
      l++;
  for (int i = pos + 1; i < n; i++)
    if (a[i] != a[pos] && a[i] != a[i - 1])
      r++;

  cout << max(l, r) * 2 << "\n";
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

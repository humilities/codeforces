#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> base;
  base.push_back(b[0]);
  for (int i = 1; i < n; i++) {
    if (b[i] != b[i - 1])
      base.push_back(b[i]);
  }

  int ap = 0, bp = 0;
  while (ap < n && bp < base.size()) {
    if (a[ap] == base[bp]) {
      bp++;
    }

    ap++;
  }

  if (bp == base.size())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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

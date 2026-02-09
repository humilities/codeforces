#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  vector<int> b(m);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
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

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  vector<int> b(m + 1);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];

  sort(a.begin(), a.end(), greater<int>());

  ll cnt = 0;
  int pos = 1;

  for (int i = 0; i < n; i++) {
    int ki = a[i];
    if (pos <= ki && b[pos] < b[ki]) {
      cnt += b[pos];
      pos++;
    } else {
      cnt += b[ki];
    }
  }

  cout << cnt << endl;
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

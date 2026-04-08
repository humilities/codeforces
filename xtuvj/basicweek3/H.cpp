#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  if ((n & 1) == 0) {
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
  int k = (n + 1) / 2;
  for (int i = 1; i <= k; i++)
    cout << i << " " << n + k + i - 1 << endl;
  for (int i = k + 1; i <= n; i++)
    cout << i << " " << n + i - k << endl;
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

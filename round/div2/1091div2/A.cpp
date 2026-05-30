#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  int sum = 0;
  vector<int> a(n);
  lin(i, 0, n) cin >> a[i], sum += a[i];

  if (sum & 1) {
    cout << "YES" << "\n";
    return;
  }

  int rem = n * k;
  if ((rem & 1) == 0) {
    cout << "YES" << "\n";
    return;
  }

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

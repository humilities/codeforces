#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int sum = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (n & 1) {
    cout << "NO" << "\n";
    return;
  }

  if (sum == 0) {
    cout << "YES" << "\n";
    return;
  }

  bool flag = false;
  for (int i = 0; i < n - 1; i++)
    if (a[i] == a[i + 1]) {
      flag = true;
      break;
    }

  if (flag && (abs(sum) % 4) == 0)
    cout << "YES" << "\n";
  else
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

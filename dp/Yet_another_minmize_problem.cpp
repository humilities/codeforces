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

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  int sum = 0;
  int tol = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i] * a[i] + b[i] * b[i];
    tol += a[i] + b[i];
  }

  bitset<100005> dp;
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    dp = (dp << a[i]) | (dp << b[i]);
  }

  int val = -1;

  for (int i = 0; i < tol; i++) {
    if (dp[i]) {
      int a = tol - i;
      int num = (n - 2) * sum + i * i + a * a;

      if (val == -1 || num < val) {
        val = num;
      }
    }
  }

  cout << val << endl;
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

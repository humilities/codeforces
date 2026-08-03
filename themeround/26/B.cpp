#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  ll max_val = -1e18; // 记录全局最大值
  bool has_positive = false;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    max_val = max(max_val, a[i]);
    if (a[i] > 0) {
      has_positive = true;
    }
  }

  // 特判：如果全是负数，直接输出最大值
  if (!has_positive) {
    cout << max_val << "\n";
    return;
  }

  // 累加奇偶位置的正数值（必须用 long long）
  ll n1 = 0, n2 = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      n1 += max(0LL, a[i]);
    else
      n2 += max(0LL, a[i]);
  }

  cout << max(n1, n2) << "\n";
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

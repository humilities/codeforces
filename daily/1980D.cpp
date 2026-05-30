#include <bits/stdc++.h>

using namespace std;

bool ok(int n, const vector<int> &a, int k) {
  if (k < 0 || k >= n)
    return false;

  int last = 0;
  int prev = -1;
  for (int i = 0; i < n; ++i) {
    if (i == k)
      continue;
    if (prev != -1) {
      int g = std::gcd(prev, a[i]);
      if (g < last)
        return false;
      last = g;
    }
    prev = a[i];
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  int bad = -1;
  int pre_g = 0;
  for (int i = 0; i < n - 1; ++i) {
    int g = std::gcd(a[i], a[i + 1]);
    if (g < pre_g) {
      bad = i;
      break;
    }
    pre_g = g;
  }

  if (bad == -1) {
    cout << "YES\n";
    return;
  }

  if (ok(n, a, bad - 1) || ok(n, a, bad) || ok(n, a, bad + 1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

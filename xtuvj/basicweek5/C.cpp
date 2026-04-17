#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int k, x, a;
  cin >> k >> x >> a;

  ll sum = 1;

  while (x) {
    x--;
    sum += sum / (k - 1) + 1;

    // cout << sum << " ";
    if (sum > a) {
      cout << "NO" << "\n";
      return;
    }
  }

  // cout << "\n";
  cout << "YES" << "\n";
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

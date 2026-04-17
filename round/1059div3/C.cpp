#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0 << "\n";
    return;
  }

  if ((a ^ b) <= a) {
    cout << 1 << endl;
    cout << (a ^ b) << endl;
    return;
  }

  ll temp = a;
  ll m = 1;

  while (temp > 0) {
    temp >>= 1;
    m <<= 1;
  }

  m -= 1;

  if (b > m) {
    cout << -1 << endl;
    return;
  } else {
    cout << 2 << endl;
    cout << (a ^ m) << " " << (m ^ b) << endl;
  }
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

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k, m;
  cin >> k >> m;

  int rem = m % 3 * k;
  int base = 2 * k - rem;
  if (rem == 0) {
    cout << 2 * k << endl;
    return;
  } else if (base < 0) {
    cout << 0 << endl;
    return;
  } else {
    cout << base << endl;
    return;
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

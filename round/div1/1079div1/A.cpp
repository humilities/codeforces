#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  ll p, q;
  cin >> p >> q;

  ll d = q - p;

  if (d > 0 && p >= 2 * d && q >= 3 * d) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
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

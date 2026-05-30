#include <bits/stdc++.h>

using namespace std;

void solve() {
  double p;
  cin >> p;

  p /= 100.0;

  double n1 = p * p * p;
  double n2 = (1 - p) * p * p * p * p;
  double n3 = p * p * p * p * (1 - p);
  double n4 = p * p * p * (1 - p);

  cout << fixed << setprecision(6) << (n1 + n2 + n3 + n4) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}

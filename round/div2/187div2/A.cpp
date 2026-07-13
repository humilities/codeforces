#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;

  int k = d / m;
  if (k == 0) {
    cout << n << endl;
    return;
  }

  k++;
  // cout << k << " ";

  int div = n / k;
  int rem = n % k;

  if (rem == 0)
    cout << div << endl;
  else
    cout << div + 1 << endl;
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

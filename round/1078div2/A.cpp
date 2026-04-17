#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, w;
  cin >> n >> w;

  int div = n / w;
  int rem = n % w;

  cout << div * (w - 1) + rem << endl;
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

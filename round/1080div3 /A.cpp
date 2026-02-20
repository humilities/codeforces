#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 67) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;

  return;
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

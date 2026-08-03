#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  bool is = true;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 67) {
      is = false;
    }
  }

  if (is)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;

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

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string a;
  cin >> a;

  int cz = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0')
      cz++;
  }
  int co = n - cz;

  if (cz % 2 == 1) {
    cout << cz << endl;
    for (int i = 0; i < n; i++) {
      if (a[i] == '0')
        cout << i + 1 << " ";
    }

    cout << endl;
  } else {
    if (co % 2 == 1) {
      cout << -1 << endl;
    } else {
      cout << co << endl;
      if (co != 0) {
        for (int i = 0; i < n; i++) {
          if (a[i] == '1')
            cout << i + 1 << " ";
        }

        cout << endl;
      }
    }
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

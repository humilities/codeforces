#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  string a, b;
  cin >> a >> b;

  int le1 = a.size();
  int le2 = b.size();

  if (a[0] == b[0]) {
    cout << "YES" << "\n";
    cout << a[0] << '*' << "\n";

    return;
  }

  if (a[le1 - 1] == b[le2 - 1]) {
    cout << "YES" << "\n";
    cout << '*' << a[le1 - 1] << "\n";

    return;
  }

  bool flag = false;
  string ans = "";
  lin(i, 1, le1) {
    lin(j, 1, le2) {
      if (a[i - 1] == b[j - 1] && a[i] == b[j]) {
        flag = true;
        ans += a[i - 1];
        ans += a[i];

        break;
      }
    }

    if (flag)
      break;
  }

  if (flag) {
    cout << "YES" << "\n";
    cout << '*' << ans << '*' << "\n";

    return;
  } else
    cout << "NO" << "\n";
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

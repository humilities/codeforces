#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  string a, b;
  cin >> a >> b;

  int len = a.size() - 1;

  bool flag = false;
  for (int i = len; i >= 0; i--) {
    if (a[i] == '1' && b[i] == '1')
      if (a[i - 1] == '0' && b[i - 1] == '0') {
        flag = true;
        break;
      }
  }

  if (flag) {
    cout << "YES" << "\n";
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

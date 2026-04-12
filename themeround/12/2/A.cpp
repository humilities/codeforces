#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int q = sqrt(n);
  if (q * q == n) {
    bool flag = false;

    lin(i, 2, q) {
      lin(j, 2, q) {
        if (s[(i - 1) * q + j - 1] == '1') {
          flag = true;
          break;
        }

        cout << (i - 1) * q + j << " ";
      }
    }

    if (flag) {
      cout << "NO" << "\n";
    } else
      cout << "YES" << "\n";

    // cout << 1 << "\n";

    return;
  } else {
    cout << "NO" << "\n";
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

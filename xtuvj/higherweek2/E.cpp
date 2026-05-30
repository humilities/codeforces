#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int can[505][505];
int len[505];

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);

  lin(i, 1, n + 1) lin(j, 1, n + 1) can[i][j] = -1;

  lin(i, 1, n + 1) {
    cin >> a[i];
    can[i][i] = a[i];
  }

  lin(len, 2, n + 1) {
    lin(i, 1, n - len + 2) {
      int ed = i + len - 1;

      lin(k, i, ed) if (can[i][k] != -1 && can[i][k] == can[k + 1][ed]) {
        can[i][ed] = can[i][k] + 1;
        break;
      }
    }
  }

  lin(i, 1, n + 1) {
    len[i] = i;
    lin(j, 0, i) if (can[j + 1][i] != -1) len[i] = min(len[i], len[j] + 1);
  }

  cout << len[n];
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

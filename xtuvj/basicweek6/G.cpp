#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int f[2][201][201];
int s[2][201][201];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  string a, b;
  cin >> a >> b;

  a = " " + a;
  b = " " + b;

  lin(i, 0, 2) s[i][0][0] = 1;

  lin(i, 1, n + 1) {
    int cur = i % 2;
    int pre = (i - 1) % 2;

    lin(j, 1, m + 1) {
      lin(l, 1, k + 1) {
        f[cur][j][l] = 0;
        s[cur][j][l] = s[pre][j][l];

        if (a[i] == b[j]) {
          f[cur][j][l] = (f[pre][j - 1][l] + s[pre][j - 1][l - 1]) % mod;
          s[cur][j][l] = (s[cur][j][l] + f[cur][j][l]) % mod;
        }
      }
    }
  }

  cout << s[n % 2][m][k] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}

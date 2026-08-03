#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn = 100005;
int f[mn];

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  lin(i, 0, n) cin >> a[i];

  int ans = 1;
  lin(i, 0, n) {
    int temp = a[i];
    vector<int> pri;

    for (int j = 2; j * j <= temp; j++) {
      if (temp % j == 0)
        pri.push_back(j);
      while (temp % j == 0)
        temp /= j;
    }
    if (temp > 1)
      pri.push_back(temp);

    int len = 0;
    for (auto k : pri)
      len = max(len, f[k]);

    len++;
    for (auto k : pri)
      f[k] = len;

    ans = max(ans, len);
  }

  cout << ans;
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

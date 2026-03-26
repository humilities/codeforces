#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;

  vector<int> ma(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    ma[x] = i;
  }

  int ans = 0;

  for (int i = 1; i * i <= 2 * n; i++) {
    if (ma[i] == 0)
      continue;

    for (int j = i + 1; j * i < 2 * n; j++) {
      if (ma[j] == 0)
        continue;

      if (i * j == ma[i] + ma[j])
        ans++;
    }
  }

  cout << ans << endl;
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

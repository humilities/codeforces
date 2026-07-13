#include <bits/stdc++.h>

using namespace std;

int sum(int x) {
  int ans = 0;

  while (x > 0) {
    ans += x % 10;
    x /= 10;
  }

  return ans;
}

void solve() {
  int x;
  cin >> x;

  if (x % 9 != 0)
    cout << 0 << endl;
  else {
    int cnt = 0;

    for (int i = x; i <= x + 99; i++) {
      if (i - sum(i) == x) {
        cnt++;
      }
    }

    cout << cnt << endl;
  }

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

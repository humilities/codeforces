#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n, p;
  cin >> n >> p;

  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll num = 0;
  ll ans = 0;

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == "halfplus") {
      num = num * 2 + 1;
      ans += (num / 2) * p + p / 2;
    }
    if (a[i] == "half") {
      num *= 2;
      ans += num / 2 * p;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

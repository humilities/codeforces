#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  ll n, c, k;
  cin >> n >> c >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    if (a[i] <= c) {
      ll use = min(k, c - a[i]);
      c += a[i];
      c += use;

      k -= use;
    }
  }

  cout << c << endl;
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

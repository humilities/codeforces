#include <bits/stdc++.h>
#include <functional>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  ll cnt = 0;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += a[i] - 1;
  }
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = a[i] + b[i] - 2;
  }

  sort(c.begin(), c.end(), greater<int>());

  for (int i = 1; i < n; i += 2) {
    cnt -= c[i];
  }

  cout << cnt << endl;
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

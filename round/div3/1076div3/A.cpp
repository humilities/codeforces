#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, s, x;
  cin >> n >> s >> x;

  int cnt = 0;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += a[i];
  }

  if (cnt == s)
    cout << "YES" << endl;
  else {
    int num = s - cnt;

    if (num % x == 0 && num > 0) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO" << endl;
      return;
    }
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

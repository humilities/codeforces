#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      cnt++;
  }

  if (cnt == 1 || cnt == n) {
    cout << 0 << endl;
    return;
  }

  int f1 = 0, p1 = 0;
  int f2 = 0, p2 = 0;
  for (int i = 0; i < n; i++)
    if (f1 == 0 && a[i] == 1) {
      p1 = i;
      break;
    }
  for (int i = n - 1; i > 0; i--)
    if (f2 == 0 && a[i] == 1) {
      p2 = i;
      break;
    }

  // cout << p1 << " " << p2 << endl;

  cout << p2 - p1 + 1 - cnt << "\n";
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

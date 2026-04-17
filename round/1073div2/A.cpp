#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  bool flag1 = true, flag2 = true;
  int c = a[0] & 1;
  int b = a[1] & 1;

  for (int i = 2; i < n; i += 2) {
    if ((a[i] & 1) != c) {
      flag1 = false;
      break;
    }
  }

  if (!flag1) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 3; i < n; i += 2) {
    if ((a[i] & 1) != b) {
      flag2 = false;
      break;
      ;
    }
  }

  if (!flag2) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}

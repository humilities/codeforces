#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n == 1) {
    cout << "Alice" << "\n";
    return;
  }

  sort(a.begin(), a.end());
  if (a[0] > 1)
    cout << "Alice" << "\n";
  else {
    int cnt = 0;
    while (cnt < n && a[cnt] == 1)
      cnt++;

    if (cnt < n) {
      if (cnt & 1)
        cout << "Bob" << "\n";
      else
        cout << "Alice" << "\n";
    } else {
      if (cnt & 1)
        cout << "Alice" << "\n";
      else
        cout << "Bob" << "\n";
    }
  }
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

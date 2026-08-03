#include <bits/stdc++.h>
#include <climits>

using namespace std;
using ll = long long;

void solve() {
  int n;
  int mi = INT_MAX;
  cin >> n;

  vector<int> a(n);
  map<int, int> ma;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);

    ma[a[i]]++;
  }

  if (ma[mi] == 1) {
    cout << "YES" << "\n";
    return;
  }

  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (a[i] % mi != 0) {
      flag = true;
      break;
    }
  }

  if (flag)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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

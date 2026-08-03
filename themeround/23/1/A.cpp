#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  vector<int> pair;
  for (int i = 0; i < n - 1;) {
    if (a[i] == a[i + 1]) {
      pair.push_back(i);
      i += 2;
    } else
      i++;
  }

  if (pair.empty()) {
    cout << -1 << "\n";
    return;
  }

  if (pair.size() >= 2) {
    int i1 = pair[pair.size() - 1];
    int i2 = pair[pair.size() - 2];

    cout << a[i1] << " " << a[i1] << " " << a[i2] << " " << a[i2] << "\n";
    return;
  }

  ll idx = pair[0];
  ll val = a[idx];

  vector<int> rem;
  for (int i = 0; i < n; i++) {
    if (i == idx || i == idx + 1)
      continue;
    rem.push_back(a[i]);
  }

  // test
  // for (int i = 0; i < rem.size(); i++)
  //   cout << rem[i] << " ";
  // cout << "\n";

  ll c = 0, d = 0;
  for (int i = 0; i < rem.size() - 1; i++) {
    c = rem[i];
    d = rem[i + 1];

    if (d - c < 2 * val) {
      cout << val << " " << val << " " << c << " " << d << "\n";
      return;
    }
  }

  cout << -1 << "\n";
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

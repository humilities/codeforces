#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  int val = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || ((a[i] != a[i - 1] + 1) && (a[i] != a[i - 1])))
      cur = 0;

    if (a[i] == a[i - 1])
      continue;

    cur++;
    val = max(val, cur);
  }
  cout << val << endl;
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

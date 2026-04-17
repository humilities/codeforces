#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> b;

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > mx)
      mx = a[i];

    if (i == mx)
      b.push_back(i);
  }

  if (b.size() <= 1) {
    for (int i = 1; i <= n; i++)
      cout << a[i] << " \n"[i == n];

    return;
  }

  if (b.size() == 2)
    swap(a[b[0]], a[b[1]]);
  else
    swap(a[b[0]], a[b[b.size() - 1]]);
  for (int i = 1; i <= n; i++)
    cout << a[i] << " \n"[i == n];

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

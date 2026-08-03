#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, h, l;
  cin >> n >> h >> l;

  if (h > l) {
    swap(h, l);
  }

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  int k = 0, m = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= h)
      k++;

    if (a[i] <= l)
      m++;
  }

  cout << min(k, (m / 2)) << endl;
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

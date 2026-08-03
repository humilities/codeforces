#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, h;
  cin >> n >> m >> h;

  vector<int> a(n);
  vector<int> cha(n, -1);
  vector<int> bas(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    bas[i] = a[i];
  }

  int las = -1;
  for (int i = 0; i < m; i++) {
    int c, b;
    cin >> c >> b;
    c--;

    if (cha[c] < las)
      a[c] = bas[c];

    a[c] += b;
    if (a[c] > h) {
      las = i;
      a[c] = bas[c];
    }

    cha[c] = i;
  }

  for (int i = 0; i < n; i++) {
    if (cha[i] < las)
      a[i] = bas[i];

    cout << a[i] << " ";
  }

  cout << " ";
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

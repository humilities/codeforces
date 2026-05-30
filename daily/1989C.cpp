#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  int neg = 0, pos = 0;
  int a1 = 0, b1 = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && b[i] == 1)
      pos++;
    else if (a[i] == -1 && b[i] == -1)
      neg++;
    else if (a[i] > b[i])
      a1 += a[i];
    else if (b[i] > a[i])
      b1 += b[i];
  }

  for (int i = 0; i < pos; i++) {
    if (a1 < b1)
      a1++;
    else
      b1++;
  }
  for (int i = 0; i < neg; i++) {
    if (a1 > b1)
      a1--;
    else
      b1--;
  }

  cout << min(a1, b1) << "\n";
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

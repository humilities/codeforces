#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int l = 0, r = n - 1;
  int cntl = a[0], cntr = a[n - 1];

  while (l <= r) {
    if (cntl < cntr) {
      l++;
      cntl += a[l];
      continue;
    } else if (cntl > cntr) {
      r--;
      cntr += a[r];
      continue;
    }

    if (cntl == cntr && l != r) {
      l++, r--;
      cntl += a[l];
      cntr += a[r];
      continue;
    }

    if (cntl == cntr && l == r) {
      l++;
    }
  }

  cout << r + 1 << " " << n - r - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

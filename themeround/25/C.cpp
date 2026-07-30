#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int x = 0;
  while ((x + 1) * (x + 2) / 2 <= k) {
    x++;
  }

  int rem = k - x * (x + 1) / 2;
  vector<int> a(n);

  for (int i = 0; i < x; i++) {
    a[i] = 2;
  }

  if (x < n) {
    a[x] = -(2 * (x - rem) + 1);
  }

  for (int i = x + 1; i < n; i++) {
    a[i] = -1000;
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? "" : " ");
  }
  cout << "\n";
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

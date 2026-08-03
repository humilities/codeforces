#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++) {
    int less = 0;
    int great = 0;

    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[i]) {
        less++;
      } else if (a[j] > a[i]) {
        great++;
      }
    }

    cout << max(less, great) << (i == n - 1 ? "" : " ");
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

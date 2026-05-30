#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int s = 500;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= s) {
      for (int j = 1; j * a[i] + i < n; j++) {
        if (a[j * a[i] + i] == j)
          ans++;
      }

      for (int j = 1; i - j * a[i] >= 0; j++) {
        if (a[i - j * a[i]] == j)
          ans++;
      }
    } else {
      for (int j = 1; j * a[i] + i < n && j < s; j++) {
        if (a[j * a[i] + i] == j)
          ans++;
      }
    }
  }

  cout << ans << endl;
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

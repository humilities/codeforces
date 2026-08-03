#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  bool flag = true;
  cin >> n;
  int c1 = 1;
  int c2 = n;

  vector<int> a(n + 1);
  for (int i = n; i > 0; i--) {
    if (flag) {
      a[i] = c1;
      c1++;
      flag = !flag;
    } else {
      a[i] = c2;
      c2--;
      flag = !flag;
    }
  }

  for (int i = 1; i <= n; i++) {
    int temp = a[n - i + 1];
    a[n - i + 1] = a[i];
    a[i] = temp;
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
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

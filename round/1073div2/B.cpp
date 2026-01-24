#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(110, 0);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    a[num]++;
  }

  if (a[0] == 0)
    cout << "NO" << endl;
  else if (a[1] > 0)
    cout << "YES" << endl;
  else
    cout << (a[0] == 1 ? "YES" : "NO") << endl;

  return;
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

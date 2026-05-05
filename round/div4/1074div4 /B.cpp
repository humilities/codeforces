#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int man = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] > man)
      man = a[i];
  }

  cout << n * man << endl;
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

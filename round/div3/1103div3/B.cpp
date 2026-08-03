#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<int> mo(k);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      mo[i % k]++;
  }

  bool flag = true;
  for (int i = 0; i < k; i++)
    if (mo[i] & 1) {
      flag = false;
      break;
    }

  if (!flag)
    cout << "NO" << "\n";
  else
    cout << "YES" << "\n";
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

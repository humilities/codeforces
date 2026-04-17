#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;

  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    int val = 1 << i;
    if (str[i] == '-')
      num[i] = -val;
    else
      num[i] = val;
  }

  string ret = "";
  for (int i = 0; i < n; i++) {
    if (k % (1 << (i + 1)) != 0) {
      ret += '#';
      k -= num[i];
    } else {
      ret += '.';
    }
  }

  if (k == 0)
    cout << ret << endl;
  else
    cout << -1 << endl;
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

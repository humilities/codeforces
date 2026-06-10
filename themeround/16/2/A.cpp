#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int c = 0;
  for (auto ch : s)
    if (ch == '0')
      c++;

  int tar = k + c - n / 2;
  if (!(tar & 1) && tar >= 0) {
    int x = tar / 2;
    if (x <= k) {
      cout << "Yes" << "\n";
      return;
    }
  }
  cout << "No" << "\n";
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

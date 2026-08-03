#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  string ans(n, ' ');
  int idx = 0;

  map<char, int> ma;
  for (char c : s)
    ma[c]++;

  vector<pair<int, char>> sh;
  for (auto [ch, val] : ma) {
    sh.push_back({val, ch});
  }

  sort(sh.begin(), sh.end());
  for (auto [val, ch] : sh) {
    for (int i = 0; i < val; i++) {
      if (idx >= n)
        idx = 1;

      ans[idx] = ch;
      idx += 2;
    }
  }

  cout << ans << "\n";
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

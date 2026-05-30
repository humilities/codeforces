#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> chu;

void pre() {
  chu.clear();

  for (int i = 0; i <= 61; i++)
    chu.push_back(to_string(1LL << i));
}

int mat(string s, string t) {
  int sp = 0, tp = 0;
  int cnt = 0;

  while (sp < s.length() && tp < t.length()) {
    if (s[sp] == t[tp]) {
      cnt++;
      tp++;
    }
    sp++;
  }

  return (s.length() - cnt) + (t.length() - cnt);
}

void solve() {
  string n;
  cin >> n;

  int res = 1e9;
  for (string &str : chu)
    res = min(res, mat(n, str));

  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool pa(string s) {
  int r = 0, l = s.size() - 1;

  while (r <= l) {
    if (s[l] != s[r]) {
      return false;
    }

    l--, r++;
  }

  return true;
}

bool di(string s) {
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] > s[i])
      return false;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;

  string str;
  cin >> str;

  for (int i = 0; i < (1 << n); i++) {
    string p = "", s = "";

    vector<int> ans;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        p += str[j];
        ans.push_back(j + 1);
      } else {
        s += str[j];
      }
    }

    if (pa(s) && di(p)) {
      cout << ans.size() << endl;

      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
      }

      return;
    }
  }

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

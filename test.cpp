#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string sche;
  cin >> sche;

  int n;
  cin >> n;

  vector<pair<set<char>, set<char>>> fds(n);
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    int pos = line.find("->");
    string left_str = line.substr(0, pos);
    string right_str = line.substr(pos + 2);
    set<char> left(left_str.begin(), left_str.end());
    set<char> right(right_str.begin(), right_str.end());
    fds[i] = {left, right};
  }

  int m;
  cin >> m;

  while (m--) {
    string query;
    cin >> query;

    set<char> result(query.begin(), query.end());

    bool chan = true;
    while (chan) {
      chan = false;
      for (auto &[left, right] : fds) {
        if (includes(result.begin(), result.end(), left.begin(), left.end())) {
          size_t last = result.size();
          result.insert(right.begin(), right.end());
          if (result.size() > last)
            chan = true;
        }
      }
    }

    string ans(result.begin(), result.end());
    cout << ans << "\n";
  }

  return 0;
}

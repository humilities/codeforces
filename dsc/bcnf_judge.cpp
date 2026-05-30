#include <bits/stdc++.h>

using namespace std;

set<char> clo(const set<char> &attrs,
                  const vector<pair<set<char>, set<char>>> &fds) {
  set<char> result = attrs;
  bool cha = true;
  while (cha) {
    cha = false;
    for (auto &[l, r] : fds) {
      if (includes(result.begin(), result.end(), l.begin(), l.end())) {
        size_t before = result.size();
        result.insert(r.begin(), r.end());
        if (result.size() > before)
          cha = true;
      }
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    string str;
    cin >> str;
    set<char> R(str.begin(), str.end());

    int m;
    cin >> m;

    vector<pair<set<char>, set<char>>> fds(m);
    for (int i = 0; i < m; i++) {
      string line;
      cin >> line;
      int pos = line.find("->");
      string ls = line.substr(0, pos);
      string rs = line.substr(pos + 2);
      fds[i] = {set<char>(ls.begin(), ls.end()),
                set<char>(rs.begin(), rs.end())};
    }

    bool isBCNF = true;
    for (auto &[left, right] : fds) {
      bool trivial =
          includes(left.begin(), left.end(), right.begin(), right.end());
      if (trivial)
        continue;

      set<char> cl = clo(left, fds);
      if (cl != R) {
        isBCNF = false;
        break;
      }
    }

    cout << (isBCNF ? "BCNF" : "None") << "\n";
  }

  return 0;
}

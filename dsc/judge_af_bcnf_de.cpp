#include <bits/stdc++.h>
using namespace std;

set<char> clo(const set<char> &attrs,
              const vector<pair<set<char>, set<char>>> &fds) {
  set<char> result = attrs;
  bool cha = true;

  while (cha) {
    cha = false;
    for (auto &[left, right] : fds) {
      if (includes(result.begin(), result.end(), left.begin(), left.end())) {
        size_t before = result.size();
        result.insert(right.begin(), right.end());
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

  int n;
  cin >> n;

  vector<string> re(n);
  for (int i = 0; i < n; i++)
    cin >> re[i];

  int m;
  cin >> m;

  vector<pair<set<char>, set<char>>> fds(m);
  for (int i = 0; i < m; i++) {
    string line;
    cin >> line;
    int pos = line.find("->");
    string ls = line.substr(0, pos);
    string rs = line.substr(pos + 2);
    fds[i] = {set<char>(ls.begin(), ls.end()), set<char>(rs.begin(), rs.end())};
  }

  for (int i = 0; i < n; i++) {
    string &rel = re[i];
    set<char> Ri(rel.begin(), rel.end());
    int sz = rel.size();

    bool is = true;

    for (int mask = 1; mask < (1 << sz); mask++) {
      set<char> alpha;
      for (int j = 0; j < sz; j++)
        if (mask >> j & 1)
          alpha.insert(rel[j]);

      set<char> cl = clo(alpha, fds);

      set<char> clr;
      set_intersection(cl.begin(), cl.end(), Ri.begin(), Ri.end(),
                       inserter(clr, clr.begin()));

      set<char> ria;
      set_difference(Ri.begin(), Ri.end(), alpha.begin(), alpha.end(),
                     inserter(ria, ria.begin()));

      set<char> extra;
      set_intersection(clr.begin(), clr.end(), ria.begin(), ria.end(),
                       inserter(extra, extra.begin()));

      if (extra.empty())
        continue;
      if (clr == Ri)
        continue;

      is = false;
      break;
    }

    cout << (is ? "BCNF" : "None") << "\n";
  }

  return 0;
}

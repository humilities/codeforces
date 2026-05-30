#include <bits/stdc++.h>
using namespace std;

set<char> clo(const set<char> &attrs,
              const vector<pair<set<char>, set<char>>> &fds) {
  set<char> result = attrs;
  bool flag = true;

  while (flag) {
    flag = false;

    for (auto &[left, right] : fds) {
      if (includes(result.begin(), result.end(), left.begin(), left.end())) {
        size_t before = result.size();
        result.insert(right.begin(), right.end());

        if (result.size() > before)
          flag = true;
      }
    }
  }

  return result;
}

bool ispre(const set<char> &alpha, const set<char> &beta,
           const vector<set<char>> &RS,
           const vector<pair<set<char>, set<char>>> &fds) {
  set<char> res = alpha;
  bool flag = true;

  while (flag) {
    flag = false;

    for (auto &Ri : RS) {
      set<char> inter;
      set_intersection(res.begin(), res.end(), Ri.begin(), Ri.end(),
                       inserter(inter, inter.begin()));

      set<char> cl = clo(inter, fds);
      set<char> t;
      set_intersection(cl.begin(), cl.end(), Ri.begin(), Ri.end(),
                       inserter(t, t.begin()));

      size_t before = res.size();
      res.insert(t.begin(), t.end());

      if (res.size() > before)
        flag = true;
    }
  }
  return includes(res.begin(), res.end(), beta.begin(), beta.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

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

  int n;
  cin >> n;

  vector<set<char>> RS(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    RS[i] = set<char>(s.begin(), s.end());
  }

  for (auto &[left, right] : fds) {
    bool res = ispre(left, right, RS, fds);
    cout << (res ? "True" : "False") << "\n";
  }

  return 0;
}

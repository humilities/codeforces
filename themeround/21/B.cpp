#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, j, k;
  cin >> n >> j >> k;

  string s = to_string(n);
  vector<string> perms;
  do {
    perms.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  string a1 = perms[j - 1];
  string a2 = perms[k - 1];

  int a = 0;
  int b = 0;
  int len = a1.length();

  vector<bool> vis1(len, false);
  vector<bool> vis2(len, false);

  for (int i = 0; i < len; i++) {
    if (a1[i] == a2[i]) {
      a++;
      vis1[i] = true;
      vis2[i] = true;
    }
  }

  for (int i = 0; i < len; i++) {
    if (vis1[i])
      continue;
    for (int j = 0; j < len; j++) {
      if (vis2[j])
        continue;
      if (a1[i] == a2[j]) {
        b++;
        vis2[j] = true;

        break;
      }
    }
  }

  cout << a << "A" << b << "B" << "\n";
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

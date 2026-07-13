#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int ba[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 4,  9,  25, 49};

void solve() {
  int cnt = 0;

  for (auto x : ba) {
    cout << x << endl;

    string s;
    cin >> s;

    if (s == "yes")
      cnt++;
    if (cnt >= 2) {
      cout << "composite" << endl;
      return;
    }
  }

  cout << "prime" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}

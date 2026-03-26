#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  if (n % 2 == 1 && s[n / 2] == '0') {
    int a = 0, b = 0;

    int flag = 1;
    for (int i = 0; i < n / 2; i++) {
      if (flag % 2 == 1 && s[i] == '0')
        b++;
      if (flag % 2 == 0 && s[i] == '0')
        a++;
    }

    // cout << a << " " << b << endl;

    if (a * 2 + 1 > b * 2)
      cout << "BOB" << endl;
    else if (a * 2 + 1 < b * 2)
      cout << "ALICE" << endl;
    else
      cout << "DRAW" << endl;
  } else {
    int a = 0, b = 0;

    int flag = 0;
    for (int i = 0; i < n / 2; i++) {
      if (flag % 2 == 1 && s[i] == '0')
        b++;
      if (flag % 2 == 0 && s[i] == '0')
        a++;
    }

    if (a * 2 > b * 2)
      cout << "BOB" << endl;
    else if (a * 2 < b * 2)
      cout << "ALICE" << endl;
    else
      cout << "DRAW" << endl;
  }
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

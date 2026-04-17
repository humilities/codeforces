#include <bits/stdc++.h>

using namespace std;

bool hui(string s) {
  int l = 0;
  int r = s.length() - 1;

  while (l <= r) {
    if (s[l++] != s[r--])
      return false;
  }

  return true;
}

void last(string s, int n) {
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

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  if (hui(s))
    last(s, n);
  else {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        cnt++;
    }

    if (n % 2 == 1 && s[n / 2] == '0' && cnt == 2)
      cout << "DRAW" << endl;
    else
      cout << "ALICE" << endl;
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

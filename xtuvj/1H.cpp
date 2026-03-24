#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  map<string, int> ma;
  while (n--) {
    string str;
    cin >> str;

    ma[str]++;

    if (ma[str] > 1) {
      cout << str << ma[str] - 1 << endl;
    } else {
      cout << "OK" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

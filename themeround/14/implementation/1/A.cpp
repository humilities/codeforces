#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int k = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      k++;
    }
  }

  if (s[0] == '0') {
    cout << max(0, k - 1) << endl;
  } else {
    cout << k << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

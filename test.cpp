#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n < 3) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll tol = 0;
  vector<int> s;
  for (int i = 0; i < n; ++i) {
    while (s.size() >= 2 && s[s.size() - 2] >= s.back() && s.back() <= a[i]) {
      tol += min(s[s.size() - 2], a[i]);
      s.pop_back();
    }
    s.push_back(a[i]);
  }

  if (s.size() > 2) {
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 2; ++i) {
      tol += s[i];
    }
  }

  cout << tol << endl;

  return 0;
}

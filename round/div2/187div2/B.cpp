#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  string x;
  cin >> x;

  vector<int> a;
  int tol = 0;
  for (int i = 0; i < x.size(); i++) {
    int num = x[i] - '0';
    tol += num;

    a.push_back(num);
  }

  if (tol < 10) {
    cout << 0 << endl;
    return;
  }

  vector<int> b(a.size());
  for (int i = 0; i < a.size(); i++) {
    if (i == 0)
      b[i] = a[i] - 1;
    else
      b[i] = a[i];
  }

  sort(b.begin(), b.end(), greater<>());

  int ans = 0;
  for (int i = 0; i < b.size(); i++) {
    tol -= b[i];
    ans++;

    if (tol < 10) {
      break;
    }
  }

  cout << ans << endl;
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

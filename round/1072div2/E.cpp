#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll suba(int length) {
  ll ret = 0;

  for (int i = length; i > 0; i--) {
    ret += length - (i - 1);
  }

  return ret;
}

void solve() {
  int n;
  cin >> n;

  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  vector<int> base(n - 1);
  for (int i = 0; i < n - 1; i++) {
    base[i] = abs(num[i + 1] - num[i]);
  }

  queue<int> op;
  vector<ll> ret(n);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (base[j] > i)
        op.push(base[j]);

      if (base[j + 1] < i) {
        ret[i] += suba(op.size());
      }
    }
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

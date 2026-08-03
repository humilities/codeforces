#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string ans;
  char ba[] = {'a', 'e', 'i', 'o', 'u'};

  int i = n / 5;
  int j = n % 5;

  for (int k = 0; k < 5; k++) {
    int cnt = i + (k < j ? 1 : 0);
    ans.append(cnt, ba[k]);
  }

  cout << ans << "\n";
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

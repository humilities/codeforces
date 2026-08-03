#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  ll n;
  cin >> n;

  ll k = 1;
  ll temp = n;
  for (int i = 2; i * i <= temp; i++) {
    if (temp % i == 0) {
      k *= i;

      while (temp % i == 0)
        temp /= i;
    }
  }

  if (temp > 1)
    k *= temp;

  cout << k << endl;
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

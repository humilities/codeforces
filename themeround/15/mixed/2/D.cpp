#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string S, T;
  cin >> S >> T;
  int n = S.size(), m = T.size();

  int best_d = INT_MIN;
  int best_i = -1, best_ss = -1;

  for (char c = 'a'; c <= 'z'; c++) {
    int min_i = -1, max_ss = -1;

    // leftmost in S[1..n-1]
    for (int i = 1; i < n; i++) {
      if (S[i] == c) {
        min_i = i;
        break;
      }
    }
    // rightmost in T[0..m-2]
    for (int ss = m - 2; ss >= 0; ss--) {
      if (T[ss] == c) {
        max_ss = ss;
        break;
      }
    }

    if (min_i == -1 || max_ss == -1)
      continue;

    int d = max_ss - min_i;
    if (d > best_d) {
      best_d = d;
      best_i = min_i;
      best_ss = max_ss;
    }
  }

  if (best_i == -1) {
    cout << -1 << "\n";
  } else {
    cout << S.substr(0, best_i + 1) << T.substr(best_ss + 1) << "\n";
  }

  return 0;
}

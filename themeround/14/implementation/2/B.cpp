#include <iostream>

using namespace std;

int check(int s1, int s2, int sl1, int sl2) {
  int suneet_score = 0;
  int slavic_score = 0;

  if (s1 > sl1)
    suneet_score++;
  else if (s1 < sl1)
    slavic_score++;

  if (s2 > sl2)
    suneet_score++;
  else if (s2 < sl2)
    slavic_score++;

  return (suneet_score > slavic_score) ? 1 : 0;
}

void solve() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;

  int ans = 0;

  ans += check(a1, a2, b1, b2); // S(a1, a2) vs L(b1, b2)
  ans += check(a1, a2, b2, b1); // S(a1, a2) vs L(b2, b1)
  ans += check(a2, a1, b1, b2); // S(a2, a1) vs L(b1, b2)
  ans += check(a2, a1, b2, b1); // S(a2, a1) vs L(b2, b1)

  cout << ans << "\n";
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

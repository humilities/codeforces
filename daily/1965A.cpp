// #include <algorithm>
// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// void solve() {
//   int n;
//   cin >> n;
//   vector<int> a(n);
//   for (int &x : a)
//     cin >> x;
//
//   sort(a.begin(), a.end());
//
//   for (int i = 0; i < n; i++) {
//     if (a[i] > i + 1) {
//       cout << (i % 2 == 0 ? "Alice" : "Bob") << endl;
//       return;
//     }
//   }
//
//   cout << (n % 2 == 1 ? "Alice" : "Bob") << endl;
// }
//
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   int t;
//   cin >> t;
//   while (t--)
//     solve();
//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  if (!(cin >> n))
    return;

  vector<int> a(n);
  int maxsize = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > maxsize) {
      maxsize = a[i];
    }
  }

  sort(a.begin(), a.end());

  int mexsize = 1;
  for (int sz : a) {
    if (sz == mexsize) {
      mexsize = mexsize + 1;
    }
  }

  if (mexsize > maxsize) {
    if (maxsize % 2 == 1)
      cout << "Alice" << endl;
    else
      cout << "Bob" << endl;
  } else {
    if (mexsize % 2 == 1)
      cout << "Alice" << endl;
    else
      cout << "Bob" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (!(cin >> t))
    return 0;
  while (t--) {
    solve();
  }
  return 0;
}

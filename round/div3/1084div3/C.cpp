#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string str;
  cin >> str;

  stack<char> st;
  for (char ch : str) {
    if (!st.empty() && st.top() == ch)
      st.pop();
    else
      st.push(ch);
  }

  if (st.empty())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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

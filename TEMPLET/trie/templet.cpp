#include <bits/stdc++.h>

using namespace std;

const int mn = 200005;

int trie[mn][26];
int is_end[mn];
int cnt = 1;

void insert(const string &s) {
  int u = 1;

  for (char ch : s) {
    int idx = ch - 'a';

    if (!trie[u][idx])
      trie[u][idx] = ++cnt;
    u = trie[u][idx];
  }

  is_end[u]++;
}

bool search(const string &s) {
  int u = 1;

  for (char ch : s) {
    int idx = ch - 'a';

    if (!trie[u][idx])
      return false;
    u = trie[u][idx];
  }

  return is_end[u] > 0;
}

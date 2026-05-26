#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l;
  Node *r;
  Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

Node *bui(vector<vector<int>> &no, int ro) {
  if (ro == 0)
    return nullptr;

  Node *node = new Node(no[ro][0]);
  node->l = bui(no, no[ro][1]);
  node->r = bui(no, no[ro][2]);

  return node;
}

Node *mer(Node *t1, Node *t2) {
  if (t1 == nullptr)
    return t2;
  if (t2 == nullptr)
    return t1;

  Node *meg = new Node(t1->val + t2->val);
  meg->l = mer(t1->l, t2->l);
  meg->r = mer(t1->r, t2->r);

  return meg;
}

void pre(Node *root, vector<int> &res) {
  if (root == nullptr)
    return;
  res.push_back(root->val);
  pre(root->l, res);
  pre(root->r, res);
}

void ino(Node *root, vector<int> &res) {
  if (root == nullptr)
    return;
  ino(root->l, res);
  res.push_back(root->val);
  ino(root->r, res);
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n1;
    cin >> n1;
    vector<vector<int>> t1(n1 + 1, vector<int>(3));
    for (int i = 1; i <= n1; i++)
      cin >> t1[i][0] >> t1[i][1] >> t1[i][2];

    int n2;
    cin >> n2;
    vector<vector<int>> t2(n2 + 1, vector<int>(3));
    for (int i = 1; i <= n2; i++)
      cin >> t2[i][0] >> t2[i][1] >> t2[i][2];

    Node *r1 = bui(t1, 1);
    Node *r2 = bui(t2, 1);

    Node *me = mer(r1, r2);

    vector<int> prer;
    pre(me, prer);
    for (int i = 0; i < prer.size(); i++) {
      if (i > 0)
        cout << " ";
      cout << prer[i];
    }
    cout << endl;

    vector<int> in;
    ino(me, in);
    for (int i = 0; i < in.size(); i++) {
      if (i > 0)
        cout << " ";
      cout << in[i];
    }
    cout << endl;
  }

  return 0;
}

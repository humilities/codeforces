//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//#define lrt (rt<<1)
//#define rrt (rt<<1 | 1)
//#define lson l,m,lrt
//#define rson m+1,r,rrt
//
//const int N = 1 << 17;
//int n, q, p, v;
//int tree[N << 2];
//
//void pushup(int rt, int flag) {
//	if (flag)   tree[rt] = tree[lrt] ^ tree[rrt];
//	else		tree[rt] = tree[lrt] | tree[rrt];
//}
//
//int build(int l, int r, int rt) {
//	if (l == r) {
//		cin >> tree[rt];
//		return 0;
//	}
//
//	int m = (l + r) >> 1;
//	int flag = build(lson);
//	build(rson);
//
//	pushup(rt, flag);
//	return flag ^ 1;
//}
//
//int update(int l, int r, int rt, int p, int v) {
//	if (l == r) {
//		tree[rt] = v;
//		return 0;
//	}
//
//	int m = (l + r) >> 1;
//	int flag;
//
//	if (p <= m) flag = update(lson, p, v);
//	else flag = update(rson, p, v);
//
//	pushup(rt, flag);
//	return flag ^ 1;
//}
//
//int main() {
//	cin >> n>>q;
//
//	build(1, 1 << n, 1);
//
//	while (q--) {
//		cin >> p >> v;
//
//		update(1, 1 << n, 1, p, v);
//		cout << tree[1] << endl;
//	}
//
//	return 0;
//}
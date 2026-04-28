//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector<int> adj[200005];
//bool vis[400005];
//int col[400005];
//
//int nodes, edges;
//bool flag = false;
//
//
//void dfs(int u, int c) {
//	if (flag) {
//		return;
//	}
//
//	vis[u] = true;
//	col[u] = c;
//	nodes++;
//
//	for (int v : adj[u]) {
//		edges++;
//		if (!vis[v]) {
//			dfs(v, -c);
//		}
//		else if(col[v]==col[u]) {
//			flag = true;
//			return;
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//
//	while (t--) {
//		int n;
//		bool ret = true;
//		cin >> n;
//
//		for (int i = 1;i <= 2 * n;i++) {
//			adj[i].clear();
//			vis[i] = false;
//			col[i] = 0;
//		}
//
//		vector<int> hash(2 * n + 1, 0);
//		vector<pair<int, int>> domi;
//
//		for (int i = 0;i < n;i++){
//			int u, v;
//			cin >> u >> v ;
//			hash[u]++;
//			hash[v]++;
//
//			if ((hash[u]>2 || hash[v] > 2)||(u==v)) {
//				cout << "NO" << endl;
//				ret = false;
//				continue;
//			}
//
//			domi.push_back({ u,v });
//		}
//
//		if (!ret) {
//			continue;
//		}
//
//		for (auto const& p : domi) {
//			adj[p.first].push_back(p.second);
//			adj[p.second].push_back(p.first);
//		}
//
//		bool name = true;
//		for (int i = 1;i <= 2 * n;i++) {
//			if (!vis[i]) {
//				nodes = 0;
//				edges = 0;
//				dfs(i, 1);
//				
//				if (flag) {
//					cout << "NO" << endl;
//					name = false;
//					break;
//				}
//			}
//		}
//		if (!name) {
//			continue;
//		}
//		cout << "YES" << endl;
//	}
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//// Maximum possible size for adjacency lists and flags
//// 2*n + 1 for vertices 1 to 2*n
//const int MAX_VERTICES = 400005;
//vector<int> adj[MAX_VERTICES];
//bool vis[MAX_VERTICES];
//int col[MAX_VERTICES];
//
//bool is_bipartite = true;
//
//// DFS function to perform two-coloring and detect odd cycles
//void dfs(int u, int c) {
//    vis[u] = true;
//    col[u] = c;
//
//    for (int v : adj[u]) {
//        if (!vis[v]) {
//            dfs(v, -c);
//            if (!is_bipartite) return; // Exit early if an odd cycle was found
//        }
//        else if (col[v] == col[u]) {
//            is_bipartite = false; // Found an odd cycle
//            return;
//        }
//    }
//}
//
//void solve() {
//    int n;
//    cin >> n;
//
//    // Reset global state for each test case
//    for (int i = 1; i <= 2 * n; ++i) {
//        adj[i].clear();
//        vis[i] = false;
//        col[i] = 0;
//    }
//    is_bipartite = true;
//
//    // Use a vector to count occurrences of each number
//    vector<int> counts(2 * n + 1, 0);
//    vector<pair<int, int>> dominoes(n);
//
//    for (int i = 0; i < n; ++i) {
//        cin >> dominoes[i].first >> dominoes[i].second;
//        counts[dominoes[i].first]++;
//        counts[dominoes[i].second]++;
//    }
//
//    // First check: any number with more than two occurrences?
//    bool possible = true;
//    for (int i = 1; i <= 2 * n; ++i) {
//        if (counts[i] > 2) {
//            possible = false;
//            break;
//        }
//    }
//
//    if (!possible) {
//        cout << "NO" << endl;
//        return;
//    }
//
//    // Construct the graph
//    for (const auto& p : dominoes) {
//        adj[p.first].push_back(p.second);
//        adj[p.second].push_back(p.first);
//    }
//
//    // Second check: check for odd cycles in each connected component
//    for (int i = 1; i <= 2 * n; ++i) {
//        if (!vis[i] && adj[i].size() > 0) {
//            dfs(i, 1);
//            if (!is_bipartite) {
//                possible = false;
//                break;
//            }
//        }
//    }
//
//    if (possible) {
//        cout << "YES" << endl;
//    }
//    else {
//        cout << "NO" << endl;
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int t;
//    cin >> t;
//    while (t--) {
//        solve();
//    }
//
//    return 0;
//}

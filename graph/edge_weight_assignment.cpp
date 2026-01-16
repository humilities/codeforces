// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;

//     vector<vector<int>> adj(n + 1);
//     vector<int> degree(n + 1, 0);

//     for (int i = 0; i < n - 1; i++) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//         degree[a]++;
//         degree[b]++;
//     }

//     // 1. 找到所有叶子节点
//     vector<int> leaves;
//     for (int i = 1; i <= n; i++) {
//         if (degree[i] == 1) {
//             leaves.push_back(i);
//         }
//     }

//     // 2. 计算最小值 f_min
//     // 通过BFS检查所有叶子是否在同一二分图部分
//     vector<int> depth(n + 1, -1);
//     vector<int> q;
//     int root = 1;
//     depth[root] = 0;
//     q.push_back(root);

//     for (int i = 0; i < q.size(); i++) {
//         int u = q[i];
//         for (int v : adj[u]) {
//             if (depth[v] == -1) {
//                 depth[v] = depth[u] + 1;
//                 q.push_back(v);
//             }
//         }
//     }

//     int first_leaf_parity = depth[leaves[0]] % 2;
//     bool all_same_parity = true;
//     for (int leaf : leaves) {
//         if (depth[leaf] % 2 != first_leaf_parity) {
//             all_same_parity = false;
//             break;
//         }
//     }

//     int f_min = all_same_parity ? 1 : 3;

//     // 3. 计算最大值 f_max
//     int f_max = n - 1;  // 初始为总边数
//     for (int v = 1; v <= n; v++) {
//         if (degree[v] == 1) continue;  // 跳过叶子节点

//         int leaf_neighbors = 0;
//         for (int u : adj[v]) {
//             if (degree[u] == 1) {
//                 leaf_neighbors++;
//             }
//         }
//         if (leaf_neighbors > 1) {
//             f_max -= (leaf_neighbors - 1);
//         }
//     }

//     cout << f_min << " " << f_max << endl;

//     return 0;
// }



//1338B

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    vector<int> leaf;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            leaf.push_back(i);
        }
    }

    vector<int> depth(n + 1, -1);
    vector<int> q;
    int root = 1;
    depth[root] = 0;

    q.push_back(root);

    for (int i = 0; i < q.size(); i++) {
        int u = q[i];

        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                q.push_back(v);
            }
        }
    }

    int Prioty = depth[leaf[0]] % 2;
    bool flag = true;

    for (int leave : leaf) {
        if (depth[leave] % 2 != Prioty) {
            flag = false;
            break;
        }
    }

    int f_min = flag ? 1 : 3;

    int f_max = n - 1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) continue;

        int cnt = 0;
        for (int j : adj[i]) {
            if (degree[j] == 1) cnt++;
        }

        if (cnt > 1) f_max -= (cnt - 1);
    }

    cout << f_min << " " << f_max;
    return 0;
}
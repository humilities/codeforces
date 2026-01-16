#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    // 使用 scanf/printf 避免 cin/cout 的 I/O 耗时
    if (!(cin >> n)) return;

    // 读取数组
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // SumMap: 键为和 S，值为第一次出现该和的索引对 (x, y)
    // S 的最大值约为 5 * 10^6，直接使用 map 或 hash array 都可以
    // 由于 n 很大，为保证速度，可以使用数组（如果内存允许）或 map
    // 此处 a_i <= 2.5e6，S <= 5e6，数组大小 5e6 + 1 可行
    // 注意：我们将索引存储为 1-based (题目要求)
    
    // pair<int, int> 存储 (x, y)，x < y
    // 使用 std::map 来避免创建巨大的静态数组
    map<long long, pair<int, int>> sum_map;

    // O(n^2) 遍历所有不同的索引对 (i, j)， i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long current_sum = (long long)a[i] + a[j];
            
            // 当前对的索引： i+1 和 j+1 (1-based)
            int current_x = i + 1;
            int current_y = j + 1;

            if (sum_map.count(current_sum)) {
                // Case 1: 找到了相同的和 S
                pair<int, int> stored_pair = sum_map[current_sum];
                int stored_z = stored_pair.first;
                int stored_w = stored_pair.second;

                // 检查四个索引是否全部不同： {current_x, current_y} 和 {stored_z, stored_w} 不相交
                // 1-based 索引
                if (current_x != stored_z && current_x != stored_w &&
                    current_y != stored_z && current_y != stored_w) {
                    
                    // 找到答案！
                    cout << "YES" << endl;
                    cout << current_x << " " << current_y << " " << stored_z << " " << stored_w << endl;
                    return; // 立即退出
                }
                // Note: 如果不相交条件不满足，根据引理，我们知道存在另外的对，
                // 比如 (i, j), (x, y) 只有 1 个共同索引，但题目暗示只需找到满足条件的即可。
                // 此时继续寻找下一个 pair (i, j).
            } else {
                // Case 2: 第一次出现该和 S
                sum_map[current_sum] = {current_x, current_y};
            }
        }
    }

    // 遍历结束仍未找到
    cout << "NO" << endl;
}

int main() {
    // 提高 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
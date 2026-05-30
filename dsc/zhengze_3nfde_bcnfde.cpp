#include <bits/stdc++.h>
using namespace std;

// ===== 数据结构 =====
struct FD {
  set<char> left, right;
  FD(set<char> l, set<char> r) : left(l), right(r) {}
};

// ===== 工具函数 =====

// 计算属性集的闭包
set<char> closure(const set<char> &attrs, const vector<FD> &fds) {
  set<char> result = attrs;
  bool changed = true;
  while (changed) {
    changed = false;
    for (auto &fd : fds) {
      if (includes(result.begin(), result.end(), fd.left.begin(),
                   fd.left.end())) {
        size_t before = result.size();
        result.insert(fd.right.begin(), fd.right.end());
        if (result.size() > before)
          changed = true;
      }
    }
  }
  return result;
}

// 判断 alpha -> beta 是否被 fds 蕴含
bool implies(const set<char> &alpha, const set<char> &beta,
             const vector<FD> &fds) {
  set<char> cl = closure(alpha, fds);
  return includes(cl.begin(), cl.end(), beta.begin(), beta.end());
}

// 字符集转字符串（有序）
string setToStr(const set<char> &s) { return string(s.begin(), s.end()); }

// 打印函数依赖集
void printFDs(const vector<FD> &fds, const string &name = "F") {
  cout << name << " = {\n";
  for (auto &fd : fds) {
    cout << "  " << setToStr(fd.left) << " -> " << setToStr(fd.right) << "\n";
  }
  cout << "}\n";
}

// 打印分解结果
void printDecomposition(const vector<set<char>> &decomp, const string &name) {
  cout << name << " = { ";
  for (auto &r : decomp)
    cout << setToStr(r) << " ";
  cout << "}\n";
}

// ===== 算法5：正则覆盖（Canonical Cover）=====
// 步骤：
// 1. 将每个FD右侧拆为单属性
// 2. 去除左侧无关属性（extraneous attributes）
// 3. 去除冗余FD
// 4. 合并相同左侧

vector<FD> canonicalCover(vector<FD> fds) {
  cout << "\n========== 算法5：正则覆盖构造 ==========\n";
  printFDs(fds, "原始F");

  // Step 1: 右侧拆为单属性
  {
    vector<FD> tmp;
    for (auto &fd : fds)
      for (char c : fd.right)
        tmp.emplace_back(fd.left, set<char>{c});
    fds = tmp;
    cout << "\n[Step1] 右侧拆单属性后：\n";
    printFDs(fds);
  }

  bool changed = true;
  while (changed) {
    changed = false;

    // Step 2: 去除左侧无关属性
    for (auto &fd : fds) {
      if (fd.left.size() <= 1)
        continue;
      for (auto it = fd.left.begin(); it != fd.left.end();) {
        char c = *it;
        set<char> newLeft = fd.left;
        newLeft.erase(c);
        // 检查用newLeft能否推出fd.right（在当前fds下）
        if (implies(newLeft, fd.right, fds)) {
          cout << "[去无关左属性] " << setToStr(fd.left) << " -> "
               << setToStr(fd.right) << "  去除左侧属性 " << c << "\n";
          fd.left = newLeft;
          it = fd.left.begin();
          changed = true;
        } else {
          ++it;
        }
      }
    }

    // Step 3: 去除冗余FD
    for (int i = 0; i < (int)fds.size();) {
      // 构造不含fds[i]的临时集合
      vector<FD> tmp;
      for (int j = 0; j < (int)fds.size(); j++)
        if (j != i)
          tmp.push_back(fds[j]);
      // 检查fds[i]是否被其余FD蕴含
      if (implies(fds[i].left, fds[i].right, tmp)) {
        cout << "[去冗余FD] 删除 " << setToStr(fds[i].left) << " -> "
             << setToStr(fds[i].right) << "\n";
        fds.erase(fds.begin() + i);
        changed = true;
      } else {
        ++i;
      }
    }
  }

  // Step 4: 合并相同左侧
  map<set<char>, set<char>> merged;
  for (auto &fd : fds)
    for (char c : fd.right)
      merged[fd.left].insert(c);
  vector<FD> result;
  for (auto &[l, r] : merged)
    result.emplace_back(l, r);

  cout << "\n[Result] 正则覆盖 Fc：\n";
  printFDs(result, "Fc");
  return result;
}

// ===== 寻找所有候选键 =====
vector<set<char>> findCandidateKeys(const set<char> &R, const vector<FD> &fds) {
  vector<set<char>> keys;
  int n = R.size();
  string attrs(R.begin(), R.end());
  // 枚举所有子集，从小到大
  for (int size = 1; size <= n; size++) {
    // 枚举所有size大小的子集
    vector<int> idx(size);
    iota(idx.begin(), idx.end(), 0);
    while (true) {
      set<char> candidate;
      for (int i : idx)
        candidate.insert(attrs[i]);
      // 检查是否已被某个已找到的键包含（超集剪枝）
      bool superOfKey = false;
      for (auto &k : keys)
        if (includes(candidate.begin(), candidate.end(), k.begin(), k.end())) {
          superOfKey = true;
          break;
        }
      if (!superOfKey) {
        set<char> cl = closure(candidate, fds);
        if (cl == R)
          keys.push_back(candidate);
      }
      // 下一个组合
      int i = size - 1;
      while (i >= 0 && idx[i] == n - size + i)
        i--;
      if (i < 0)
        break;
      idx[i]++;
      for (int j = i + 1; j < size; j++)
        idx[j] = idx[j - 1] + 1;
    }
  }
  return keys;
}

// ===== 算法6：3NF分解 =====
// 步骤：
// 1. 求正则覆盖Fc
// 2. 对Fc中每个 alpha->beta，创建关系 R_i = alpha ∪ beta
// 3. 若没有任何分解包含候选键，则加入一个候选键关系
// 4. 去除被包含的冗余关系

vector<set<char>> decompose3NF(const set<char> &R, const vector<FD> &fds) {
  cout << "\n========== 算法6：3NF分解 ==========\n";

  vector<FD> Fc = canonicalCover(fds);

  cout << "\n[Step2] 为Fc中每个FD构造子模式：\n";
  vector<set<char>> decomp;
  for (auto &fd : Fc) {
    set<char> ri;
    ri.insert(fd.left.begin(), fd.left.end());
    ri.insert(fd.right.begin(), fd.right.end());
    decomp.push_back(ri);
    cout << "  R(" << setToStr(ri) << ")\n";
  }

  // Step 3: 若无子模式包含候选键，加入候选键
  auto keys = findCandidateKeys(R, fds);
  bool hasKey = false;
  for (auto &ri : decomp) {
    for (auto &k : keys) {
      if (includes(ri.begin(), ri.end(), k.begin(), k.end())) {
        hasKey = true;
        break;
      }
    }
    if (hasKey)
      break;
  }
  if (!hasKey && !keys.empty()) {
    cout << "[Step3] 加入候选键 R(" << setToStr(keys[0]) << ")\n";
    decomp.push_back(keys[0]);
  }

  // Step 4: 去除冗余（被包含）
  vector<set<char>> final_decomp;
  for (int i = 0; i < (int)decomp.size(); i++) {
    bool redundant = false;
    for (int j = 0; j < (int)decomp.size(); j++) {
      if (i != j && includes(decomp[j].begin(), decomp[j].end(),
                             decomp[i].begin(), decomp[i].end())) {
        redundant = true;
        break;
      }
    }
    if (!redundant)
      final_decomp.push_back(decomp[i]);
  }

  cout << "\n[Result] 3NF分解结果：\n";
  printDecomposition(final_decomp, "ρ");
  return final_decomp;
}

// ===== 算法7：BCNF分解 =====
// 步骤（递归）：
// 找一个违反BCNF的FD alpha->beta（alpha不是超键且非平凡）
// 分解为 R1 = alpha+ ∩ R，R2 = R - (alpha+ - alpha)
// 递归处理

vector<set<char>> decomposeBCNF(const set<char> &R, const vector<FD> &fds) {
  // 检查R是否满足BCNF（用原始F）
  // 对R的每个非空子集alpha，检查
  string attrs(R.begin(), R.end());
  int n = attrs.size();

  for (int mask = 1; mask < (1 << n); mask++) {
    set<char> alpha;
    for (int j = 0; j < n; j++)
      if (mask >> j & 1)
        alpha.insert(attrs[j]);

    set<char> cl = closure(alpha, fds);

    // cl ∩ R
    set<char> cl_in_R;
    set_intersection(cl.begin(), cl.end(), R.begin(), R.end(),
                     inserter(cl_in_R, cl_in_R.begin()));

    // extra = cl_in_R - alpha（非平凡部分）
    set<char> extra;
    set_difference(cl_in_R.begin(), cl_in_R.end(), alpha.begin(), alpha.end(),
                   inserter(extra, extra.begin()));

    if (extra.empty())
      continue; // 平凡
    if (cl_in_R == R)
      continue; // alpha是超键

    // 违反BCNF，分解
    // R1 = cl_in_R（alpha的闭包与R的交）
    set<char> R1 = cl_in_R;
    // R2 = R - extra = alpha ∪ (R - cl_in_R)
    set<char> R2 = alpha;
    for (char c : R)
      if (cl_in_R.find(c) == cl_in_R.end())
        R2.insert(c);

    cout << "  [分解] R(" << setToStr(R)
         << ") 违反BCNF的FD: " << setToStr(alpha) << " -> " << setToStr(extra)
         << "\n"
         << "    => R1(" << setToStr(R1) << "), R2(" << setToStr(R2) << ")\n";

    // 递归
    vector<set<char>> result;
    auto d1 = decomposeBCNF(R1, fds);
    auto d2 = decomposeBCNF(R2, fds);
    result.insert(result.end(), d1.begin(), d1.end());
    result.insert(result.end(), d2.begin(), d2.end());
    return result;
  }

  // R已满足BCNF
  return {R};
}

vector<set<char>> bcnfDecomposition(const set<char> &R, const vector<FD> &fds) {
  cout << "\n========== 算法7：BCNF分解 ==========\n";
  cout << "原始模式 R(" << setToStr(R) << ")\n";
  auto result = decomposeBCNF(R, fds);
  cout << "\n[Result] BCNF分解结果：\n";
  printDecomposition(result, "ρ");
  return result;
}

// ===== 主函数：演示 =====
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // ------- 示例1 -------
  // R = ABCDE
  // F = {A->BC, CD->E, B->D, E->A}
  cout << "########## 示例1 ##########\n";
  cout << "R = ABCDE\n";
  cout << "F = {A->BC, CD->E, B->D, E->A}\n";
  {
    set<char> R = {'A', 'B', 'C', 'D', 'E'};
    vector<FD> fds = {
        FD({'A'}, {'B', 'C'}),
        FD({'C', 'D'}, {'E'}),
        FD({'B'}, {'D'}),
        FD({'E'}, {'A'}),
    };

    auto keys = findCandidateKeys(R, fds);
    cout << "候选键: ";
    for (auto &k : keys)
      cout << setToStr(k) << " ";
    cout << "\n";

    canonicalCover(fds);
    decompose3NF(R, fds);
    bcnfDecomposition(R, fds);
  }

  cout << "\n########## 示例2 ##########\n";
  cout << "R = ABCD\n";
  cout << "F = {A->B, B->C, C->D, D->A}\n";
  {
    set<char> R = {'A', 'B', 'C', 'D'};
    vector<FD> fds = {
        FD({'A'}, {'B'}),
        FD({'B'}, {'C'}),
        FD({'C'}, {'D'}),
        FD({'D'}, {'A'}),
    };

    auto keys = findCandidateKeys(R, fds);
    cout << "候选键: ";
    for (auto &k : keys)
      cout << setToStr(k) << " ";
    cout << "\n";

    canonicalCover(fds);
    decompose3NF(R, fds);
    bcnfDecomposition(R, fds);
  }

  cout << "\n########## 示例3 ##########\n";
  cout << "R = ABCDE\n";
  cout << "F = {AB->C, C->A, BC->D, ACD->B, D->EG, BE->C, CG->BD, CE->AG}\n";
  // 去掉G（不在ABCDE），简化
  cout << "F = {AB->C, C->A, BC->D, ACD->B, D->E, BE->C}\n";
  {
    set<char> R = {'A', 'B', 'C', 'D', 'E'};
    vector<FD> fds = {
        FD({'A', 'B'}, {'C'}),      FD({'C'}, {'A'}), FD({'B', 'C'}, {'D'}),
        FD({'A', 'C', 'D'}, {'B'}), FD({'D'}, {'E'}), FD({'B', 'E'}, {'C'}),
    };

    auto keys = findCandidateKeys(R, fds);
    cout << "候选键: ";
    for (auto &k : keys)
      cout << setToStr(k) << " ";
    cout << "\n";

    canonicalCover(fds);
    decompose3NF(R, fds);
    bcnfDecomposition(R, fds);
  }

  return 0;
}

#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 1000, "t");
    inf.readEoln();
    int sum_n = 0;
    while (t--) {
        int n = inf.readInt(1, 100000, "n");
        inf.readEoln();
        sum_n += n;
        for (int i = 0; i < n; i++) {
            inf.readInt(1, 1000000000, "a_i");
            if (i < n - 1) inf.readSpace();
        }
        inf.readEoln();
    }
    ensuref(sum_n <= 200000, "Sum of n exceeds 200000");
    inf.readEof();
}
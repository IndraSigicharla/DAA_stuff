#include <iostream>
#include <vector>
#include <set>
using namespace std;


set<string> do_thing(auto& table, string x, string y, int m, int n) {
    set<string> s;

    if (m == 0 || n == 0) {
        s.insert("");
        return s;
    }

    if (x[m - 1] == y[n - 1]) {
        set<string> tmp = do_thing(table, x, y, m - 1, n - 1);
        for (string str : tmp) s.insert(str + x[m - 1]);
    } else {
        if (table[m - 1][n] >= table[m][n - 1]) s = do_thing(table, x, y, m - 1, n);
        if (table[m][n - 1] >= table[m - 1][n]) {
            set<string> tmp = do_thing(table, x, y, m, n - 1);
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}

int find_len(auto& table, string x, string y) {
    for (int i = 0; i <= x.length(); i++) {
        for (int j = 0; j <= y.length(); j++) {
            if (i == 0 || j == 0) table[i][j] = 0;
            else if (x[i - 1] == y[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    return table[x.length()][y.length()];
}

int main() {
    string x, y;
    cin >> x >> y;
    vector<vector<int>> table(100, vector<int>(100));
    find_len(table, x, y);
    set<string> s = do_thing(table, x, y, x.length(), y.length());
    for (string str : s) cout << str << endl;
}

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef vector<vector<int>> mVec;

void matrixChainOrder(vector<int> p, mVec &m, mVec &s) {
    int n = p.size() - 1;
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i - 1][j - 1] = numeric_limits<int>::max();
            for (int k = i; k <= j - 1; k++) {
                int q = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1] * p[k] * p[j];
                if (q < m[i - 1][j - 1]) {
                    m[i - 1][j - 1] = q;
                    s[i - 1][j - 1] = k;
                }
            }
        }
    }
}

void printer(mVec &s, int i, int j) {
    if (i == j) cout << "A" << i;
    else {
        cout << "(";
        printer(s, i, s[i - 1][j - 1]);
        printer(s, s[i - 1][j - 1] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    mVec m(n - 1, vector<int>(n - 1, 0));
    mVec s(n - 1, vector<int>(n - 1, 0));
    matrixChainOrder(p, m, s);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (m[i][j] == 0) continue;
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[i][j] == 0) continue;
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    cout << m[0][n - 2] << endl;
}

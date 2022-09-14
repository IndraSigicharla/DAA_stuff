#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef vector<vector<int>> mVec;

int doMultiply(vector<int> const &arr, int i, int j, auto& lookup, auto& s) {
    if (j <= i + 1) return 0;

    int min = numeric_limits<int>::max();
    if (lookup[i][j] == 0) {
        for (int k = i + 1; k <= j - 1; k++) {
            int cost = doMultiply(arr, i, k, lookup, s);
            cost += doMultiply(arr, k, j, lookup, s);
            cost += arr[i] * arr[k] * arr[j];
            if (cost < min) {
                s[i][j] = k;
                min = cost;
            }
        }
        lookup[i][j] = min;
    }
    return lookup[i][j];
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    mVec lookup(n + 1, vector<int>(n + 1));
    mVec s(n + 1, vector<int>(n + 1, 0));
    int a = doMultiply(p, 0, n - 1, lookup, s);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 1; j < n; j++) {
            if (lookup[i][j] == 0) continue;
            cout << lookup[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 0) continue;
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << a;
}

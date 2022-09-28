#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#define MAX(a, b) ((a > b) ? a : b)

int lcs_length(string x, string y, int x_index = 0, int y_index = 0) {
    int m = x.length(), n = y.length();
    if ((x_index >= m) || (y_index >= n)) return 0;
    if (x[x_index] == y[y_index]) return lcs_length(x, y, x_index + 1, y_index + 1) + 1;
    else return MAX(lcs_length(x, y, x_index, y_index + 1), lcs_length(x, y, x_index + 1, y_index));
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << lcs_length(x, y);
}

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int matrix_chain_mul(int i, int j, vector<int>& thing) {
    int min_cost = numeric_limits<int>::max(), lCost, rCost, tCost;
    if (i == j) return 0;
    for (int k = i; k < j; k++) {
        lCost = matrix_chain_mul(i, k, thing);
        rCost = matrix_chain_mul(k + 1, j, thing);
        tCost = lCost + rCost + thing[i - 1] * thing[k] * thing[j];
        if (tCost < min_cost) min_cost = tCost;   
    }
    return min_cost;
}

int main() {
    int n, ele, i;
    vector<int> p;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> ele;
        p.push_back(ele);
    }
    cout << matrix_chain_mul(1, n - 1, p);
}

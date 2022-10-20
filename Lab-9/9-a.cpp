// Naive string matching

#include <iostream>
#include <string>
using namespace std;

bool check_pattern(string T, string P, int s) {
    int m = P.length();
    for (int i = 0; i < m; i++) if (P[i] != T[s + i + 1]) return false;
    return true;
}

void naive_string_matcher(string T, string P) {
    int n = T.length(), m = P.length();
    for (int s = -1; s <= n - m - 1; s++) if (check_pattern(T, P, s)) cout << "Pattern occurs at " << s + 1 << endl;
}

int main() {
    string T, P;
    cin >> T >> P;
    naive_string_matcher(T, P);
}

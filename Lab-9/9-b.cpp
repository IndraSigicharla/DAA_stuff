// Rabin-Karp Algorithm

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int valueOf(char ch) { return (ch - '0'); }

bool check_characters(string T, string P, int s) {
    int m = P.length();
    for (int i = 0; i < m; i++) if (P[i] != T[s + i + 1]) return false;
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q) {
    int p = 0, t0 = 0;
    int n = T.length(), m = P.length(), h = (int) pow(d, m - 1) % q;
    cout << "h value is " << h << endl;
    for (int i = 0; i < m; i++) {
        p = (d * p + valueOf(P[i])) % q;
        t0 = (d * t0 + valueOf(T[i])) % q;
    }
    
    for (int s = -1; s < n - m; s++) {
        cout << p << " " << t0 << endl;
        if (p == t0) if (check_characters(T, P, s)) cout << "Pattern occurs at index " << s + 1 << endl;
        if (s < n - m) t0 = (d * (t0 - valueOf(T[s + 1]) * h) + valueOf(T[s + m + 1])) % q;
    }
}

int main() {
    string T, P;
    int d, q;
    cin >> T >> P;
    cout << "Enter base and prime number";
    cin >> d >> q;
    rabin_karp_matcher(T, P, d, q);
}

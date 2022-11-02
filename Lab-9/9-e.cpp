// Rabin - fix bug

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void rabin_karp_matcher(string T, string P, int d, int q) {
	int m = P.length(), n = T.length();
	int i, j;
	int p = 0, t = 0, h = (int) pow(d, m - 1) % q;
	for (i = 0; i < m; i++) {
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}
	for (i = 0; i <= n - m; i++) {
		if (p == t) {
			for (j = 0; j < m; j++) if (T[i + j] != P[j]) break;
			if (j == m) cout << i << endl;
		}
		if (i < n - m) {
			t = (d * (t - T[i] * h) + T[i + m]) % q;
			if (t < 0) t += q;
		}
	}
}

int main() {
    string T, P;
    int d,q;
    cin >> T >> P;
    cin >> d >> q;
    rabin_karp_matcher(T, P, d, q);
}

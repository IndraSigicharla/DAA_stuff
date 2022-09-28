#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <cstring>
using namespace std;

int memo[100][100] = {-1};


int lcs(string x, string y, int px, int py)
{
    int ans;
    int m1, m2;
    if (memo[px][py] > -1) {
         return memo[px][py];
    }
    
    if ((px == 0) || (py == 0)) {
        ans = 0;
    } else if (x[px - 1] == y[py - 1]) {
        ans = lcs(x, y, px - 1, py - 1) + 1;
    } else {
        m1 = lcs(x, y, px    , py - 1);
        m2 = lcs(x, y, px - 1, py    );
        //max (m1, m2)
        if (m1 > m2) {
            ans = m1;
        } else {
            ans = m2;
        }
    }
    memo[px][py] = ans;
    return ans;
}

int print_thing() {
    px = strlen("marvin");
py = strlen("panic");
pos = 0;
while ((px != 0) && (py != 0)) {
    if (x[px - 1] == y[py - 1]) {
        res[pos++] = x[px - 1];
        px--;
        py--;
    } else if (memo[px - 1][py] > memo[px][py -1]) {
        px--;
    } else {
        py--;
    }
}
res[pos] = '\0';
printf("%s\n", strrev(res));    
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin>>a>>b;
    memset(memo, -1, sizeof(memo));
    // cout<<lcs(a,b,a.length(), b.length())<<endl;
    cout << lcs("marvin", "panic", strlen("marvin"), strlen("panic"));
    for (int i = 0; i < strlen("marvin") +  1; i++) {
        for (int j = 0; j < strlen("panic") + 1; j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
void lcs_length(string x, string y, vector<vector<int>> &c)
{
    int m, n, i, j;
    m = x.length();
    n = y.length();
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
            }
            else
            {
                c[i][j] = c[i][j - 1];
            }
        }
    }
}
void print_LCS(vector<vector<int>> &c, string x, string y, int i, int j, string &lcs)
{
    if ((i == 0) || (j == 0))
        return;
    if (x[i - 1] == y[j - 1])
    {
        print_LCS(c, x, y, i - 1, j - 1, lcs);
        lcs += x[i - 1];
    }
    else if (c[i - 1][j] >= c[i][j - 1])
    {
        print_LCS(c, x, y, i - 1, j, lcs);
    }
    else
        print_LCS(c, x, y, i, j - 1, lcs);
}
int main()
{
    string x, y;
    cin >> x >> y;
    vector<vector<int>> c(x.length() + 1, vector<int>(y.length() + 1, 0));
    lcs_length(x, y, c); // constructing c table
    string lcs = "";
    print_LCS(c, x, y, x.length(), y.length(), lcs);
    cout << c[x.length()][y.length()] << endl;
    cout << lcs << endl;
}

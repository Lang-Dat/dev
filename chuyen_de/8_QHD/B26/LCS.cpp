/**
 *	author: Lang Dat
 *	create: 29-10-2022 41:41:15
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
string x, y, ans = "";
int n, m;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LCS.INP", "r", stdin);
    // freopen("./TEST/TEST/LCS/test01/LCS.INP", "r", stdin);
    freopen("./LCS.OUT", "w", stdout);

    std::cin >> x >> y;
    n = x.size(); m = y.size();

    dp.resize(n + 1, vector<int>(m + 1, int()));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (x[i-1] == y[j-1]) ? dp[i-1][j-1] + 1:
            max(dp[i-1][j], dp[i][j-1]);
        }
    }
    std::vector<int> a, b;
    if (x[n-1] == y[m-1]) {
        a.push_back(n);
        b.push_back(m);
        ans.push_back(x[m-1]);
    }
    for (int i = n, j = m; i > 0 && j > 0;) {
        if (x[i-1] == y[j-1]) {
            a.push_back(i);
            b.push_back(j);
            ans.push_back(x[i-1]);
            i--; j--;
        } 
        else if (dp[i][j] == dp[i-1][j]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    std::cout << ans << "\n";
    for (int i = a.size() - 1; i >= 0; i--) 
        std::cout << a[i] << " ";
    std::cout << "\n";
    for (int i = a.size() - 1; i >= 0; i--) 
        std::cout << b[i] << " ";
    return 0;
}
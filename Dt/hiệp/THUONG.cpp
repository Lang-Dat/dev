#include <bits/stdc++.h>
using namespace std;
const int N = 333 + 5;
long long m, n, a[N + 5][N + 5], dp[N + 5][N + 5];

int main()
{
    freopen("THUONG.inp", "r", stdin);
    freopen("THUONG.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
        dp[i][1] = a[i][1];
    for (int j = 2; j <= n; j++)
        for (int i = 1; i <= m; i++)
        {
            if (i == 1)
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j - 1]);
            else if (i == m)
                dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]);
            else
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i + 1][j - 1]));
            dp[i][j] += a[i][j];
        }
    long long kq = INT64_MIN;
    for (int i = 1; i <= m; i++)
        kq = max(kq, dp[i][n]);
    cout << kq;
    return 0;
}
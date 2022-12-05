/**
 *	author: Lăng Trọng Đạt
 *	create: 05-12-2022 09:02:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1e3 + 5;
bool dp[LIM][LIM]; // denote str[i...j] is palindrome or not
int prefix_sum[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DEMXAUDX.INP", "r", stdin);
    freopen("./DEMXAUDX.OUT", "w", stdout);
    #endif

    int n, q, start, end;
    string str;
    std::cin >> n >> q >> str;

    for (int l = n - 1; l >= 0; l--) {
        dp[l][l] = 1;
        dp[l][l+1] = ((l < n - 1) ? str[l] == str[l+1] : 0);
        for (int r = l + 2; r < n; r++)
            dp[l][r] = dp[l+1][r-1] && str[l] == str[r];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++)
            prefix_sum[i] += (int)(dp[j][i - 1]);
        prefix_sum[i] += prefix_sum[i-1];
    }   

    while (std::cin >> start >> end)
        std::cout << prefix_sum[end] - prefix_sum[start - 1] << "\n";
    return 0;
}
/**
 *	author: Lang Dat
 *	create: 13-11-2022 14:45:10
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e3 + 5;
int nums[LIM][LIM], dp[LIM][LIM];
int m, n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GARBAGE.INP", "r", stdin);
    freopen("./GARBAGE.OUT", "w", stdout);
    #endif

    std::cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> nums[i][j];

    for (int i = m; i > 0; i--)
        for (int j = n; j > 0; j--)
            dp[i][j] = max({dp[i+1][j], dp[i+1][j+1], dp[i+1][j-1]}) + nums[i][j];

    int id = max_element(dp[1], dp[1] + n) - dp[1];
    std::cout << dp[1][id] << "\n";
    for (int i = 1, j = id; i <= m; i++) {
        std::cout << j << "\n";
        if (dp[i][j] - nums[i][j] == dp[i+1][j+1])
            j = j + 1;
        else if (dp[i][j] - nums[i][j] == dp[i+1][j-1])
            j = j - 1;
    }
    return 0;
}
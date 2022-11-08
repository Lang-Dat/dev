/**
 *	author: Lang Dat
 *	create: 03-11-2022 42:53:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1e2 + 5;
unsigned int dp[LIM][LIM], ans = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ROBOT.INP", "r", stdin);
    freopen("./ROBOT.OUT", "w", stdout);

    int n, k, x, y, middle;
    std::cin >> n >> k;
    middle = n / 2 + 1;
    for (int i = middle; i > 0; i--)
        for (int j = middle; j > 0; j--) {
            if (i == middle && j == middle) continue;
            else if (i == middle) dp[i][j] = dp[i][j + 1] + 10;
            else if (j == middle) dp[i][j] = dp[i + 1][j] + 10;
            else dp[i][j] = min({dp[i+1][j+1] + 15, dp[i+1][j] + 10, dp[i][j+1] + 10});
            dp[2*middle-i][j] = dp[i][j];
            dp[2*middle-i][2*middle-j] = dp[i][j];
            dp[2*middle-i][2*middle-j] = dp[i][j];
        }
    while (std::cin >> x >> y)
        ans += dp[x][y];
    std::cout << ans << "";
    return 0;
}
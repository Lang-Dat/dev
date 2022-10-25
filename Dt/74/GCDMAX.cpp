/**
 *	author: Lang Dat
 *	create: 25-10-2022 29:16:09
**/
#include <iostream>
using namespace std;

const int LIM = 1e6 + 6;
int dp[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./GCDMAX.INP", "r", stdin);
    // freopen("./GCDMAX.OUT", "w", stdout);

    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < LIM; i++) {
        dp[i] = dp[i-1];
        for (int j = dp[i - 1]; j <= i / 2; j++) {
            if (i / j > 1) dp[i] = j;           
        }
    }
    int t, n;
    std::cin >> t;
    while (std::cin >> n)
    {
        std::cout << dp[n] << "\n";
    }
    
    return 0;
}
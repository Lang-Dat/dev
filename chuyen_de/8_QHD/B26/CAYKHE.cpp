/**
 *	author: Lang Dat
 *	create: 13-11-2022 36:19:11
**/
#include <iostream>
#include <vector>
using namespace std;

static const int LIM = 1e2 + 2;
int values[LIM], weights[LIM], dp[LIM][LIM];
int n, W;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CAYKHE.INP", "r", stdin);
    freopen("./CAYKHE.OUT", "w", stdout);
    #endif

    std::cin >> n >> W;

    for (int i = 1; i <= n; i++)    
        std::cin >> values[i] >> weights[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    std::cout << dp[n][W] << "\n";
    vector<int> items;
    for (int i = n, j = W; i > 0; i--) {
        if (dp[i][j] == dp[i-1][j-weights[i]] + values[i]) {
            j -= weights[i];
            items.push_back(i);
        }
    }
    std::cout << items.size() << " ";
    for (int i = items.size() - 1; i >= 0; i--)
        std::cout << items[i] << " ";
    return 0;
}
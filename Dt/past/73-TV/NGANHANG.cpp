/**
 *	author : Lăng Trọng Đạt
 *	creater: 02-02-2023 09:53:02
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 100 + 5;
static int coins[LIM], freq[LIM];
int n, amount;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NGANHANG.INP", "r", stdin);
    freopen("./NGANHANG.OUT", "w", stdout);

    std::cin >> n >> amount;
    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }
    
    vector<int64_t> dp(amount + 1, INT32_MAX), truy(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin = 0; coin < n; coin++) {
            if (i >= coins[coin] and  dp[i - coins[coin]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[coin]] + 1;
                truy[i] = coin;
            }
        }
    }

    std::cout << dp[amount] << "\n";

    int truy_vet = amount;
    while (truy[truy_vet] != -1) {
        freq[truy[truy_vet]]++;
        truy_vet = truy_vet - coins[truy[truy_vet]];
    }

    for (int i = 0; i < n; i++)
        std::cout << freq[i] << " ";
    return 0;
}
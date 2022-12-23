/**
 *	author: Lang Dat
 *	create: 18-11-2022 12:38:20
**/
#include <iostream>
using namespace std;

static const int LIM = 40*500000 + 5;
int dp[40][LIM];
int nums[40];
int n, target, k, ans = 0;



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    // freopen("./GAME.INP", "r", stdin);
    // freopen("./GAME.OUT", "w", stdout);
    #endif

    std::cin >> n >> target >> k;
    k--;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    target -= nums[k];
    std::cout << ans << "";
    return 0;
}
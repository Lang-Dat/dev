/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 30:19:09
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int MOD = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5_trau.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    uint64_t nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    uint64_t ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int z = j + 1; z < n; z++)
                ans = (ans + nums[i]*nums[j]*nums[z]);

    std::cout << ans << "";

    return 0;
}
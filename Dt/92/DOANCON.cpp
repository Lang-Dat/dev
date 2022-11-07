/**
 *	author: Lang Dat
 *	create: 07-11-2022 50:13:15
**/
#include <iostream>
using namespace std;

const int LIM = 1e5 + 5;
int nums[LIM], dp[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DOANCON.INP", "r", stdin);
    freopen("./DOANCON.OUT", "w", stdout);
    #endif

    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        //int nums[n];
        for (int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }
        dp[n-1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            if ((nums[j] >= 0 && nums[j + 1] < 0) ||
                (nums[j] < 0 && nums[j + 1] >= 0)) {
                    dp[j] = 1 + dp[j + 1];
                }
            else {
                dp[j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << dp[i] << " ";
        }
    }
    return 0;
}
/**
 *	author: Lang Dat
 *	create: 05-11-2022 45:36:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1e5 + 5;
int nums[LIM], dp[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TDSTT.INP", "r", stdin);
    freopen("./TDSTT.OUT", "w", stdout);
    #endif

    int n, best = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (__gcd(nums[i], nums[j]) > 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }

    std::cout << best + 1 << "";
}
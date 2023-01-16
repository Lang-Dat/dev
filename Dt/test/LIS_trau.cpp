/**
 *	author: Lăng Trọng Đạt
 *	create: 07-12-2022 45:13:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./LIS.INP", "r", stdin);
    freopen("./LIS_trau.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;

    cout << *std::max_element(dp.begin(), dp.end());

    return 0;
}
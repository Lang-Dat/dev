/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 07:44:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

// static const int LIM = 1e5 + 5;
static const int LIM = 10;
static int nums[LIM], pre_sum[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CANDIES.INP", "r", stdin);
    freopen("./CANDIES.OUT", "w", stdout);
    #endif

    int n, q;
    std::cin >> n >> q;
    //int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    
    sort(nums + 1, nums + n + 1, greater<int>());

    for (int i = 1; i <= n; i++) {
        pre_sum[i] = pre_sum[i-1] + nums[i];
    }

    int request;
    while (std::cin >> request) {
        int ind = lower_bound(pre_sum, pre_sum + n, request) - pre_sum;
        if (ind == n) {
            std::cout << -1 << "\n";
        } else {
            std::cout << ind << "\n";
        }
    }
    return 0;
}
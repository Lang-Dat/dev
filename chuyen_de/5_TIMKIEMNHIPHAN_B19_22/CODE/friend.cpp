/**
 *	author: Lăng Trọng Đạt
 *	create: 23-11-2022 50:25:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long

static const int LIM = 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./friend.INP", "r", stdin);
    freopen("./friend.OUT", "w", stdout);
    #endif

    int n, target;
    std::cin >> n >> target;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums, nums + n);
    ull ans = 0;
    for (int i = 0; i < n; i++) {
        auto lower = lower_bound(nums + i + 1, nums + n, target - nums[i]);
        auto upper = upper_bound(lower, nums + n, target - nums[i]);
        if (lower != nums + n)
            ans += upper - lower;
    }
    std::cout << ans << "";
    return 0;
}
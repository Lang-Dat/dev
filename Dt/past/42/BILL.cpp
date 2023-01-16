/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 42:49:19
**/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

static const int LIM = 1e5 + 5;
static std::pair<uint64_t, uint64_t> nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BILL.INP", "r", stdin);
    freopen("./BILL.OUT", "w", stdout);
    #endif

    uint64_t n, s, count = 0;
    std::cin >> n >> s;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i].first >> nums[i].second;
    }
    sort(nums, nums + n);

    for (int i = 0; i < n and s > nums[i].first; i++) {
        count += min(s / nums[i].first, nums[i].second);
        s -= min(s / nums[i].first, nums[i].second)*nums[i].first;
    }

    std::cout << count<< "";
    return 0;
}
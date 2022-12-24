/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 09:43:14
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2*1e5 + 5;
// static const int LIM = 5;
static int64_t nums[LIM];
int64_t total = 0;
int64_t m, tan_cong, phong_thu;
int n;

int64_t count_if_choice(int ind) {
    int64_t ans = 0;
    if (ind == n) {
        ans = phong_thu - nums[n-1];
        if (total - nums[n-1] < tan_cong)
            ans += tan_cong - (total - nums[n-1]);
    } else {
        if (nums[ind] < phong_thu)
            ans += phong_thu - (nums[ind]);
        if (total - nums[ind] < tan_cong)
            ans += tan_cong - (total - nums[ind]);
    }
    return ans;
}
int64_t counting() {
    int64_t ans = INT32_MAX;
    int ind = lower_bound(nums, nums + n, phong_thu) - nums;
    if (ind != 0) 
        ans = count_if_choice(ind - 1);
    ans = min(ans, count_if_choice(ind));
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DRAGON.INP", "r", stdin);
    freopen("./DRAGON.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        total += nums[i];
    }

    sort(nums, nums + n);

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> phong_thu >> tan_cong;
        std::cout << counting() << "\n";
    }
    
    return 0;
}
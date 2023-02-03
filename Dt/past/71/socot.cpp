/**
 *	author : Lăng Trọng Đạt
 *	creater: 29-01-2023 20:09:40
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int64_t nums[LIM];
int64_t n, k, ans;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./socot.INP", "r", stdin);
    freopen("./socot.OUT", "w", stdout);
    #endif

    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums, nums + n, greater<int64_t>());

    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) continue;
        int count = i * (nums[i-1] - (nums[i] + 1) + 1);

        if (count <= k) {
            k -= count;
            ans += count * (nums[i-1] + (nums[i] + 1)) / 2;
            // db(ans, i, count)
            if (k == 0) {
                std::cout << ans << "";
                return 0;
            }
        } else {
            int so_lan = k / i; // 
            k -= so_lan*i;
            int64_t first = nums[i-1] - so_lan + 1;
            ans += i * (nums[i-1] + first) * so_lan / 2;
            // db(so_lan, first, ans )
            std::cout << ans + k * (first - 1) << "";
            return 0;
        }
        // db(ans, count, i, k, nums[i]);
    }
    return 0;
}
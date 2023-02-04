/**
 *	author : Lăng Trọng Đạt
 *	creater: 01-02-2023 10:27:46
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int64_t nums[LIM], pre_sum[LIM], max_h = 0;
int64_t n, m, q;

int process() {
    int64_t lo = 0, hi = max_h, res = 0;
    while (lo <= hi) {
        int64_t mid = (hi + lo) / 2;
        int ind = upper_bound(nums, nums + n, mid) - nums;
        int64_t sum = pre_sum[n] - pre_sum[ind] - (n - ind) * mid;
        if (sum >= m) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }   

    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SAW.INP", "r", stdin);
    freopen("./SAW.OUT", "w", stdout);
    #endif

    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        max_h = max(max_h, nums[i]);
    }
    sort(nums, nums + n);
    for (int i = 1; i <= n; i++)
        pre_sum[i] = pre_sum[i - 1] + nums[i - 1];

    while (std::cin >> m) {
        std::cout << process() << " ";
    }

    return 0;
}
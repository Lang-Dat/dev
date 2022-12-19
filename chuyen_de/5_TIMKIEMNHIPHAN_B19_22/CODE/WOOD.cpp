/**
 *	author: Lăng Trọng Đạt
 *	create: 24-11-2022 23:16:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long

static const int LIM = 1e6 + 5;
ull nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./WOOD.INP", "r", stdin);
    freopen("./WOOD.OUT", "w", stdout);
    #endif

    ull n, target, max_h = 0;
    std::cin >> n >> target;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        max_h = max(max_h, nums[i]);
    }
    sort(nums, nums + n);        
    int l = 0, r = max_h - 1, res = 0;
    // O(Log(max(nums))*N)
    while (l <= r) {
        int mid = (l + r) / 2;
        ull sum = 0;
        int ind = upper_bound(nums, nums + n, mid) - nums;
        for (int i = ind; i < n; i++) {
            sum += nums[i] - mid;
        }
        if (sum < target) {
            r = mid - 1;
        } else {
            l = mid + 1;
            res = mid;
        }
    }
    cout << res;
    return 0;
}
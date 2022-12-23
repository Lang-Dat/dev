/**
 *	author: Lang Dat
 *	create: 18-10-2022 02:39:16
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const ll LIM = 2 * 1e5 + 5;
ll nums[LIM];
ll n;

ll min_diff(int bigger, int i) {
    ll max_val = max({nums[i], nums[bigger] - nums[i], nums[n] - nums[bigger]});
    ll min_val = min({nums[i], nums[bigger] - nums[i], nums[n] - nums[bigger]});
    return max_val - min_val;
}
ll effecient() {
    ll lowest = INT32_MAX;
    for (ll i = 1; i < n; i++) {
        ll bigger = lower_bound(nums + i + 1, nums + n, (nums[n] - nums[i]) / 2 + nums[i]) - nums;
        lowest = min({lowest, min_diff(bigger, i), min_diff(bigger - 1, i)});
    }
    return lowest;
}
ll bruceForce() {
    // just use two loop
    ll lowest = INT64_MAX;
    for (ll i = 1; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll max_val = max({nums[i], nums[j] - nums[i], nums[n] - nums[j]});
            ll min_val = min({nums[i], nums[j] - nums[i], nums[n] - nums[j]});
            lowest = min(lowest, max_val - min_val);
        }
    }
    return lowest;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ChiaKeo.INP", "r", stdin);
    freopen("./ChiaKeo.OUT", "w", stdout);

    std::cin >> n;
    for (ll i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
    
    std::cout << effecient();
    return 0;
}
/**
 *	author: Lang Dat
 *	create: 18-10-2022 02:39:16
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 2 * 1e5 + 5;
int nums[LIM];
int n;

int effecient() {
    int lowest = INT32_MAX;
    for (int i = 1; i < n; i++) {
        int bigger = lower_bound(nums + i + 1, nums + n, (nums[n] - nums[i]) / 2 + nums[i]) - nums;
        int max_val = max({nums[i], nums[bigger] - nums[i], nums[n] - nums[bigger]});
        int min_val = min({nums[i], nums[bigger] - nums[i], nums[n] - nums[bigger]});
        lowest = min(lowest, max_val - min_val);
    }
    return lowest;
}
int bruceForce() {
    // just use two loop
    int lowest = INT32_MAX;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int max_val = max({nums[i], nums[j] - nums[i], nums[n] - nums[j]});
            int min_val = min({nums[i], nums[j] - nums[i], nums[n] - nums[j]});
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
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
    
    // std::cout << bruceForce() << " ";
    std::cout << effecient();
    return 0;
}
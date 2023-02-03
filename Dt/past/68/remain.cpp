/**
 *	author : Lăng Trọng Đạt
 *	creater: 31-01-2023 21:20:57
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int LIM = 100 + 5;
static int nums[LIM];
int n;

bool is_ac(int d) {
    for (int i = 1; i < n; i++) {
        if (nums[i] % d != nums[i - 1] % d)
            return false;
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./remain.INP", "r", stdin);
    freopen("./remain.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    int min_diff = INT32_MAX;
    sort(nums, nums + n);

    for (int i = 0; i + 1 < n; i++) {
        min_diff = min(min_diff, nums[i + 1] - nums[i]);
    }

    std::vector<int> can_d; // uoc cua min_diff
    for (int i = 1; i * i <= min_diff; i++) {
        if (min_diff % i == 0) {
            can_d.push_back(i);
            can_d.push_back(min_diff / i);
        }
    }

    sort(can_d.begin(), can_d.end(), greater<int>());

    for (int i : can_d) {
        if (is_ac(i)) {
            std::cout << i << "";
            return 0;
        }
    }
    std::cout << 1 << "";
    return 0;
}
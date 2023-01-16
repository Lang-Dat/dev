/**
 *	author : Lăng Trọng Đạt
 *	creater: 15-01-2023 08:05:02
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2*1e5 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DARR.INP", "r", stdin);
    freopen("./DARR_trau.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            best = max(best, (nums[i] >= nums[j]) ? nums[i] % nums[j] : nums[j] % nums[i]);
        }
    }
    std::cout << best << "";
    return 0;
}
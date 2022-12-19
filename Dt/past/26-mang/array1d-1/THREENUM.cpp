/**
 *	author: Lăng Trọng Đạt
 *	create: 16-12-2022 00:19:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
int64_t nums[LIM];
int64_t memory[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./THREENUM.INP", "r", stdin);
    freopen("../../../chuyen_de/3_MANG_B7_15/array1D_1/THREENUM/test0/THREENUM.INP", "r", stdin);
    // freopen("./THREENUM.OUT", "w", stdout);
    #endif

    int64_t n, max_ = INT64_MIN;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        // db(memory[i], i, min_, max_)
        std::cin >> nums[i];
        memory[i] = max(memory[i-1], 2*max_ - 3*nums[i]);
        max_ = max(max_, nums[i]);
    }

    int64_t best = 0;
    max_ = INT64_MIN;
    for (int i = n - 1; i > 1; i--) {
        max_ = max(nums[i], max_);
        best = max(best, 5*max_ + memory[i - 1]);
        // db(i, best, max_, memory[i-1])
    }

    std::cout << best << "";

    return 0;
}
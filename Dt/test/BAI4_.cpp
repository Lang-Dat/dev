/**
 *	author: Lăng Trọng Đạt
 *	create: 24-11-2022 31:53:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long

static const int LIM = 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    int n, max_ = INT32_MIN, min_ = INT32_MAX, best = INT32_MAX;
    std::vector<int> max_pos, min_pos;
    std::cin >> n;    
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        max_ = max(max_, nums[i]);
        min_ = min(min_, nums[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] == max_) max_pos.push_back(i);
        if (nums[i] == min_) min_pos.push_back(i);
    }
    for (int maxx : max_pos) {
        auto r = lower_bound(min_pos.begin(), min_pos.end(), maxx);
        if (r != min_pos.end()) {
            best = min(best, *r - maxx);
        }
        if (r != min_pos.begin())
            best = min(best, maxx - *(r-1));
    }
    std::cout << best + 1<< "";
    return 0;
}
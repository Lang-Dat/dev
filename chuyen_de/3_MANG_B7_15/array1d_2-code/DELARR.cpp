/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 43:49:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DELARR.INP", "r", stdin);
    freopen("./DELARR.OUT", "w", stdout);
    #endif

    int n;
    int64_t sum = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    sort(nums, nums + n);
    int count = 0;
    for (int l = 0, r = n - 1; sum != 0 and l <= r; count++) {
        if (sum > 0) sum -= nums[r--];
        else sum -= nums[l++];
    }

    std::cout << count << "";
    return 0;
}
/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 51:18:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM], arr[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SEQGAME.INP", "r", stdin);
    freopen("./SEQGAME.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    sort(nums, nums + n);
    sort(arr, arr + n);

    int minimum = INT32_MAX, tmp = INT32_MAX;

    for (int i = 0; i < n and minimum; i++) {
        int ind = lower_bound(arr, arr + n, -nums[i]) - arr;
        if (ind != n) minimum = min(minimum, arr[ind] + nums[i]);
        if (ind != 0) tmp = std::abs(nums[i] + arr[ind-1]);
        minimum = min(minimum, tmp);
    }

    std::cout << minimum << "";

    return 0;
}
/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 07:35:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 5*1e5 + 5;
static int nums[LIM], pre_sum[LIM], index[(int)1e3 + 10]; // index[i]: vị trí đầu tiên của phần tử i trong dãy
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./quantrong.OUT", "w", stdout);
    freopen("./quantrong.INP", "r", stdin);
    #endif

    int n, best = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        pre_sum[i] = pre_sum[i-1] + nums[i];
        if (index[nums[i]] == 0)
            index[nums[i]] = i;
    }
    
    for (int i = n; i > 0; i--) {
        if (index[nums[i]] != 0)
            best = max(best, pre_sum[i] - pre_sum[index[nums[i]] - 1]);
    }

    std::cout << best << "";
    return 0;
}
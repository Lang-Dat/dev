/**
 *	author : Lăng Trọng Đạt
 *	creater: 05-02-2023 07:33:08
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2e6 + 5;
static int nums[LIM], dem[LIM];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHONKG.INP", "r", stdin);
    freopen("./CHONKG.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        if (i >= nums[i])
            dem[i - nums[i]]++;
    }
    
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if (i + nums[i] < n)
            ans += dem[i + nums[i]];
    }

    std::cout << ans << "";

}
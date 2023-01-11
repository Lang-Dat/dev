/**
 *	author : Lăng Trọng Đạt
 *	creater: 07-01-2023 54:44:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./trungthuong.INP", "r", stdin);
    freopen("./trungthuong.OUT", "w", stdout);
    #endif

    int n, ans = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        int min_ = nums[i], max_ = nums[i];
        for (int j = i + 1; j < n and (nums[i] == min_ or nums[i] == max_); j++) {
            min_ = min(min_, nums[j]);
            max_ = max(max_, nums[j]);
            ans += ((nums[j] == min_ and nums[i] == max_) or
                      (nums[j] == max_ and nums[i] == min_));     
        }
    }

    std::cout << ans << "";
    return 0;
}
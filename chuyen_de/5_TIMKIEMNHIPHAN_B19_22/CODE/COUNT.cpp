/**
 *	author: Lăng Trọng Đạt
 *	create: 20-12-2022 47:50:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM];
int num;
int n, k;

bool check(int len) {
    // kiểm tra là có thể tạo ra một dãy số giống nhau với độ dài là len hay không
    int require = 0;

    // 6 0
    // 2 2 2 3 3 3

    for (int i = 0; i < len - 1; i++) {
        require += nums[len - 2] - nums[i];
    }
    // db(require, len)
    for (int i = len - 1; i < n; i++) {
        require += (len - 1) * (nums[i] - nums[i-1]);
        if (require <= k) {
            num = nums[i];
            // db(num, i, require, len)
            return true;
        }
        require -= (nums[i] - nums[i - len + 1]); 
    }
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./COUNT.OUT", "w", stdout);
    freopen("./COUNT.INP", "r", stdin);
    // freopen("../tknp/COUNT/test01/COUNT.INP", "r", stdin);
    #endif

    std::cin >> n >> k;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
        
    sort(nums, nums + n);
    int l = 2, r = n;
    int best = 1, value = INT32_MAX;

    while (l <= r) {
        int len = (l + r) / 2;
        if (check(len)) {
            // db(len, num)
            best = len;
            value = min(value, num);
            l = len + 1;
        } else r = len - 1;
    }

    std::cout << best << " " << value;
    return 0;
}
/**
 *	author: Lang Dat
 *	create: 18-10-2022 46:37:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Value
{
    int val, index, so_to_tra = 0;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NGANHANG.INP", "r", stdin);
    // freopen("./NGANHANG/NGANHANG/Test7/NGANHANG.INP", "r", stdin);
    freopen("./NGANHANG.OUT", "w", stdout);

    int n, m, count = 0;
    std::cin >> n >> m;
    Value nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i].val;
        nums[i].index = i;
    }
    
    sort(nums, nums + n, [](Value &a, Value &b) -> bool {
        return a.val < b.val;
    });

    for (int i = n - 1; i >= 0 && m > 0; i--) {
        nums[i].so_to_tra += m / nums[i].val;
        count += nums[i].so_to_tra;
        m %= nums[i].val;
    }
    sort(nums, nums + n, [](Value &a, Value &b) -> bool {
        return a.index < b.index;
    });

    std::cout << count << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << nums[i].so_to_tra << " ";
    }
    return 0;
}
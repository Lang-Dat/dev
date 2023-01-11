/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 20:30:19
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./ABC.INP", "r", stdin);
    freopen("./ABC.OUT", "w", stdout);
    #endif

    int nums[3];
    std::cin >> nums[0] >> nums[1] >> nums[2];

    sort(nums, nums + 3);

    char c;
    while (std::cin >> c)
        std::cout << nums[c - 'A'] << " ";

    return 0;
}
/**
 *	author: Lăng Trọng Đạt
 *	create: 11-12-2022 24:03:18
**/
#include <iostream>
#include <algorithm>
#include <stdio.h>  
using namespace std;

static const int LIM = 1e6 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./capsocong.INP", "r", stdin);
    freopen("./capsocong.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums, nums + n);
    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i-1] != nums[i-1] - nums[i-2]) {
            std::cout << "no";
            return 0;
        }
    }    
    std::cout << "yes\n";
    for (int i = 0; i < n; i++) {
        std::cout << nums[i] << " ";
    }

    return 0;
}
/**
 *	author: Lăng Trọng Đạt
 *	create: 24-11-2022 09:09:20
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
    freopen("./RANNUM.INP", "r", stdin);
    freopen("./RANNUM.OUT", "w", stdout);
    #endif

    int n, best = INT32_MAX;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    return 0;
}
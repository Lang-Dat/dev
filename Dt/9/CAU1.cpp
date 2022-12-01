/**
 *	author: Lăng Trọng Đạt
 *	create: 01-12-2022 50:21:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CAU1.INP", "r", stdin);
    freopen("./CAU1.OUT", "w", stdout);
    #endif

    int64_t n;
    std::cin >> n;
    cout << n / 2 - (n & 1 ? n : 0); 

    return 0;
}
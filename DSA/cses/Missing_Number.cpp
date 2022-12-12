/**
 *	author: Lăng Trọng Đạt
 *	create: 12-12-2022 15:03:08
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2*1e5 + 5;
bool mark[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, tmp;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        mark[tmp] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            std::cout << i << "";
            return 0;
        }
    }
    return 0;
}
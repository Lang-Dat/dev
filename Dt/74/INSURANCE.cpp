/**
 *	author : Lăng Trọng Đạt
 *	creater: 03-02-2023 19:57:07
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2e5 + 5;
static int nums[LIM];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./INSURANCE.INP", "r", stdin);
    freopen("./INSURANCE.OUT", "w", stdout);

    double total;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    return 0;
}
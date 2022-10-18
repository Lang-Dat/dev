/**
 *	author: Lang Dat
 *	create: 18-10-2022 02:39:16
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 2 * 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ChiaKeo.INP", "r", stdin);
    freopen("./ChiaKeo.OUT", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
    

    return 0;
}
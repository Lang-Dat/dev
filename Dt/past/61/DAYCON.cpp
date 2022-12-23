/**
 *	author: Lang Dat
 *	create: 16-10-2022 35:41:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYCON.INP", "r", stdin);
    freopen("./DAYCON.OUT", "w", stdout);

    ll tmp, prev, n, best = INT64_MIN, sum;
    std::cin >> n >> sum;
    best = max(best, sum);
    while (std::cin >> tmp) {
        sum = max(tmp, sum + tmp);
        best = max(best, sum);
    }

    std::cout << best;
    return 0;
}
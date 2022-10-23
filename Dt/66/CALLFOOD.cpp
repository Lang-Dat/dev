/**
 *	author: Lang Dat
 *	create: 23-10-2022 00:35:07
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

struct Food {
    ull if_first = 0, cost = 0, diff;
    int index;
};
const int LIM = 5 * 1e5 + 10;
Food f[LIM];
ull pre_sum[LIM]; 
int n;
ull curr_sum, min_first = INT32_MAX;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CALLFOOD.INP", "r", stdin);
    freopen("./CALLFOOD.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> f[i].if_first >> f[i].cost;
        f[i].diff = f[i].cost - f[i].if_first;
        if (f[i].if_first < min_first) {
            min_first = f[i].if_first;
        }
    }
    
    sort(f, f + n, [](Food &a, Food &b) {
        return a.cost < b.cost;
    });

    for (int i = 1; i <= n; i++) {
        pre_sum[i] += f[i].cost + pre_sum[i - 1];
        f[i].index = i;
    }

    Food min = f[1]; // store min first cost;
    for (int i = 2; i <= n; i++) {
        if ((min.cost + f[i].if_first) < (min.if_first + f[i].cost)) {
            min = f[i];
        }
    }
    std::cout << min_first << "\n";
    for (int i = 2; i <= n; i++) {
        curr_sum = pre_sum[i];
        curr_sum += min.if_first;
        if (min.index >= i) {
            curr_sum -= f[i].cost;
        } else {
            curr_sum -= f[min.index].cost;
        }
        std::cout << curr_sum << "\n";
    }
    return 0;
}
/**
 *	author: Lang Dat
 *	create: 23-10-2022 00:35:07
 *	[25-10-2022 21:55:21] Bug lưu ý về kiểu giữ liệu, có thể có số âm và > 2^31 nên phải dùng ll
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

struct Food {
    ll a = 0, b = 0, diff;
    int index;
};
const int LIM = 5 * 1e5 + 10;
Food f[LIM];
ll min_f[LIM]; // min from last to begin e.g min_f[k ... n] = min(f[k].a, .., f[k].n) 
ll max_diff[LIM];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CALLFOOD.INP", "r", stdin);
    freopen("./CALLFOOD.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> f[i].a >> f[i].b;
        f[i].diff = f[i].b - f[i].a;
    }
    
    sort(f, f + n, [](Food &f1, Food &f2) {
        return f1.b < f2.b;
    });

    min_f[n-1] = f[n-1].a;
    max_diff[0] = f[0].diff;
    for (int l = 1, r = n - 2; l < n; l++, r--) {
        min_f[r] = min(f[r].a, min_f[r+1]);
        max_diff[l] = max(f[l].diff, max_diff[l - 1]);
    }

    ll curr_sum = 0;
    for (int i = 0; i < n; i++) {
        curr_sum += f[i].b;
        ll sum = min(curr_sum - max_diff[i], curr_sum - f[i].b + min_f[i]);
        std::cout << sum << "\n";
    }
    return 0;
}